import os
import subprocess as sps

def file_exists(file):
    return os.path.exists(file)

def print_file(TestId, Instruction, Author, Exit, Message):
    print("TestId: " + TestId)
    print("Instruction: " + Instruction)
    print("Author: " + Author)
    print("Exit: " + Exit)
    print("Message: " + Message)

p_parser = "parser/bin/parser"
p_tests = "benchmark_src/tests/"
p_tests_code = "benchmark_src/tst_bench_txt/"
p_tests_binary = "benchmark_src/tst_bench_bin/"

simulator = "bin/mips_simulator"

files = os.listdir(p_tests)

for file in files:
    file = open(p_tests + file)

    TestId = file.readline()[8:-1]
    Instruction = file.readline()[13:-1]
    Author = file.readline()[8:-1]
    Expected_Exit = file.readline()[6:-1]
    Message =  file.readline()[9:-1]

    #print_file(TestId, Instruction, Author, Exit, Message);

    #add some protection later
    if(not file_exists(p_tests_binary + TestId + ".bin")):
        sps.call([p_parser, p_tests_code + TestId + ".txt", p_tests_binary + TestId + ".bin"], stderr=sps.PIPE, stdout=sps.PIPE)


    exit = sps.call([simulator, p_tests_binary + TestId + ".bin"], stderr=sps.PIPE)

    Status = "Pass" if (int(Expected_Exit) == exit) else "Fail"

    # TestId , Instruction , Status , Author [, Message]
    print(TestId + " , " + Instruction + " , " + Status + " , " + Author + " , " + Message)
    file.close()
