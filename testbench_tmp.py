import os
import subprocess as sps

def file_exists(test_file):
    #print("file exists")
    return os.path.lexists(test_file)

def create_bin(test_file, TestId, p_parser, p_tests_binary):
    print("entered")
    par = sps.Popen([p_parser],stdin=sps.PIPE, stderr=sps.PIPE, stdout=sps.PIPE)
    code = ""
    next_line = test_file.readline()
    next_line = test_file.readline()
    while(next_line != None and next_line != ""):
        code = code + next_line;
        next_line = test_file.readline()
    code = code + "exit\n" + p_tests_binary + TestId + ".bin\n"
    print(code)
    par.communicate(input = code.encode())

def print_file(TestId, Instruction, Author, Exit, Message):
    print("TestId: " + TestId)
    print("Instruction: " + Instruction)
    print("Author: " + Author)
    print("Exit: " + Exit)
    print("Message: " + Message)

#p_parser = "parser"
p_parser = "C:/Users/Andrzej Kowalewski/OneDrive - Imperial College London/Computer Laboratory/Year 2/MIPS/arch2-2018-cw-respectingPolice/parser.exe"
p_tests = "C:/Users/Andrzej Kowalewski/OneDrive - Imperial College London/Computer Laboratory/Year 2/MIPS/arch2-2018-cw-respectingPolice/benchmark_src/all_tests/"
p_tests_binary = "C:/Users/Andrzej Kowalewski/OneDrive - Imperial College London/Computer Laboratory/Year 2/MIPS/arch2-2018-cw-respectingPolice/benchmark_src/tst_bench_bin/"

simulator = "C:/Users/Andrzej Kowalewski/OneDrive - Imperial College London/Computer Laboratory/Year 2/MIPS/arch2-2018-cw-respectingPolice/bin/mips_simulator.exe"
print("jestem tu")
parser_exists = file_exists(p_parser)
print("parser_exist: ", parser_exists )

files = os.listdir(p_tests)

for file_name in sorted(files):
    test_file = open(p_tests + file_name)
    TestId = test_file.readline()[8:-1]
    Instruction = test_file.readline()[13:-1]
    Author = test_file.readline()[8:-1]
    Expected_Exit = test_file.readline()[6:-1]
    Message =  test_file.readline()[9:-1]
    print(TestId + " this part done")
    #print_file(TestId, Instruction, Author, Expected_Exit, Message);
    #print((parser_exists and not file_exists(p_tests_binary + TestId + ".bin"))
    print(not file_exists(p_tests_binary + TestId + ".bin"))
    print(p_tests_binary + TestId + ".bin")
    if(parser_exists and not file_exists(p_tests_binary + TestId + ".bin")):
        print("entered create if")
        create_bin(test_file, TestId, p_parser, p_tests_binary)

    if(file_exists(p_tests_binary + TestId + ".bin")):
        exit = sps.call([simulator, p_tests_binary + TestId + ".bin"], stderr=sps.PIPE)
        #print("\nexit: {}".format(exit))
        Status = "Pass" if (int(Expected_Exit) == exit) else "Fail"
        # TestId , Instruction , Status , Author [, Message]
        #print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , " + Message)
    test_file.close()
