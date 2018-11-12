import os
import subprocess as sps

def file_exists(file):
    return os.path.exists(file)

def create_bin(file, TestId, p_parser, p_tests_binary):
    par = sps.Popen([p_parser],stdin=sps.PIPE, stderr=sps.PIPE, stdout=sps.PIPE)
    code = ""
    next_line = file.readline()
    next_line = file.readline()
    while(next_line != None and next_line != ""):
        code = code + next_line;
        next_line = file.readline()
    code = code + "exit\n" + p_tests_binary + TestId + ".bin\n"
    par.communicate(input = code.encode())

def print_file(TestId, Instruction, Author, Exit, Message):
    print("TestId: " + TestId)
    print("Instruction: " + Instruction)
    print("Author: " + Author)
    print("Exit: " + Exit)
    print("Message: " + Message)

p_parser = "parser/bin/parser"
#p_parser = "parser.exe"
p_tests = "benchmark_src/tests/"
p_tests_binary = "benchmark_src/tst_bench_bin/"

simulator = "bin/mips_simulator"

parser_exists = file_exists(p_parser)

files = os.listdir(p_tests)

for file_name in files:
    file = open(p_tests + file_name)
    TestId = file.readline()[8:-1]
    Instruction = file.readline()[13:-1]
    Author = file.readline()[8:-1]
    Expected_Exit = file.readline()[6:-1]
    Message =  file.readline()[9:-1]
    #print_file(TestId, Instruction, Author, Exit, Message);

    if(parser_exists and not file_exists(p_tests_binary + TestId + ".bin")):
        create_bin(file, TestId, p_parser, p_tests_binary)
        #create_bin u mnie nie działa...

    if(file_exists(p_tests_binary + TestId + ".bin")):
        exit = sps.call([simulator, p_tests_binary + TestId + ".bin"], stderr=sps.PIPE)
        print("\nexti: {}".format(exit))
        Status = "Pass" if (int(Expected_Exit) == exit) else "Fail"
        # TestId , Instruction , Status , Author [, Message]
        print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , " + Message)
    file.close()
