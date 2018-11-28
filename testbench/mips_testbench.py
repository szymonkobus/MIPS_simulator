import os
import subprocess as sps
import sys
import codecs

def file_exists(file):
    return os.path.exists(file)

def create_bin(file, TestId, p_parser, p_tests_binary):
    par = sps.Popen([p_parser],stdin=sps.PIPE, stderr=sps.PIPE, stdout=sps.PIPE)
    code = ""
    next_line = file.readline()
    next_line = file.readline()
    while(next_line != None and next_line != ""):
        code = code + next_line
        next_line = file.readline()
    code = code + "exit\n" + p_tests_binary + TestId + ".bin\n"
    par.communicate(input = code.encode())

def print_file(TestId, Instruction, Author, Exit, Message):
    print("TestId: " + TestId)
    print("Instruction: " + Instruction)
    print("Author: " + Author)
    print("Exit: " + Exit)
    print("Message: " + Message)

p_parser = "bin/mips_parser"
p_tests = "testbench/src/"
p_tests_binary = "testbench/bin/"

timeout_sec = 5

simulator = "bin/mips_simulator"
if(len(sys.argv) > 1):
    simulator = sys.argv[1]

parser_exists = file_exists(p_parser)

files = os.listdir(p_tests)
for file_name in sorted(files):
    file = open(p_tests + file_name)
    TestId = file.readline()[8:-1]
    Instruction = file.readline()[13:-1]
    Author = file.readline()[8:-1]
    Expected_Exit = file.readline()[6:-1]
    Message =  file.readline()[9:-1]

    if(parser_exists and not file_exists(p_tests_binary + TestId + ".bin")):
        create_bin(file, TestId, p_parser, p_tests_binary)

    if(file_exists(p_tests_binary + TestId + ".bin")):
        sim = sps.Popen([simulator, p_tests_binary + TestId + ".bin"], stderr=sps.PIPE, stdout = sps.PIPE)
        try:
            out, err = sim.communicate(timeout=timeout_sec)
            exit = sim.returncode
            Status = "Pass" if (int(Expected_Exit) == exit) else "Fail"
        except sps.TimeoutExpired:
            sim.kill()
            Status = "Fail"
            exit = 'timeout'
        if(Status == "Fail"):
            print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , "
                + Message + " ex:" + Expected_Exit + " act:" + str(exit))
        else:
            print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , "
                + Message)
    file.close()

p_tests =  "testbench/src_IO/"
files_IO = os.listdir(p_tests)
for file_name in sorted(files_IO):
    file = codecs.open(p_tests + file_name, encoding = 'utf-8')

    TestId = file.readline()[8:-1]
    Instruction = file.readline()[13:-1]
    Author = file.readline()[8:-1]
    Expected_Exit = file.readline()[6:-1]
    Message =  file.readline()[9:-1]
    IO = file.readline()[4:-1]
    IO_func = IO[0]
    IO_char = 'EOF' if (len(IO) == 1) else IO[1]
    if IO_char == '0': IO_char = '\0'

    if(parser_exists and not file_exists(p_tests_binary + TestId + ".bin")):
        create_bin(file, TestId, p_parser, p_tests_binary)

    if(file_exists(p_tests_binary + TestId + ".bin")):
        sim = sps.Popen([simulator, p_tests_binary + TestId + ".bin"], stdin = sps.PIPE, stderr = sps.PIPE, stdout = sps.PIPE)
        if IO_char == 'EOF':
            try:
                out, err = sim.communicate(timeout=timeout_sec)
                exit = sim.returncode
                Status = "Pass" if (int(Expected_Exit) == exit) else "Fail"
            except sps.TimeoutExpired:
                sim.kill()
                Status = "Fail"
        elif IO_func == 'w': #testbench writes to simulator / tests GETCHAR
            try:
                out, err = sim.communicate(IO_char.encode('iso8859-1'), timeout=timeout_sec)
                exit = sim.returncode
                Status = "Pass" if (ord(IO_char) == exit or int(Expected_Exit) == exit) else "Fail"
            except sps.TimeoutExpired:
                sim.kill()
                Status = "Fail"
        elif IO_func == 'r': #testbench reads output from simulator / tests PUTCHAR
            try:
                out, err = sim.communicate(timeout=timeout_sec)
                if len(out) > 0:
                    IO_char_out = (out.decode('iso8859-1'))[0]
                else:
                    IO_char_out = '\xFE'
                exit = sim.returncode
                Status = "Pass" if (ord(IO_char_out) == ord(IO_char) or int(Expected_Exit) == exit) else "Fail"
            except sps.TimeoutExpired:
                sim.kill()
                Status = "Fail"

        print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , " + Message)
    file.close()
