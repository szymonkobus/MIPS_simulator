import os
import subprocess as sps
from shutil import rmtree as rm
from shutil import move as switch_dir
import sys

def exists(test_file):
    return os.path.exists(test_file)

def create_bin(test_file, TestId, p_parser, p_tests_binary):
    code = ""
    next_line = test_file.readline()
    next_line = test_file.readline()
    while(next_line != None and next_line != ""):
        code = code + next_line;
        next_line = test_file.readline()
    out_name = TestId
    out_bin_name = out_name + '.mips.bin'
    out_s = open(p_tests_binary + out_name + '.s', 'wb+')
    out_s.write(code)
    out_s.close()
    out_call = "make " + p_tests_binary + out_bin_name
    mips_gnu = sps.call(out_call, shell=True, stdout=sps.PIPE, stderr=sps.PIPE)

def print_file(TestId, Instruction, Author, Exit, Message):
    print("TestId: " + TestId)
    print("Instruction: " + Instruction)
    print("Author: " + Author)
    print("Exit: " + Exit)
    print("Message: " + Message)

simulator = "bin/simulator"
if(len(sys.argv) > 1):
    simulator = sys.argv[1]

p_parser = "mips-parser-master/bin/parser"
p_tests = "benchmark_src/all_tests/"
p_tests_binary = "benchmark_src/tst_bench_bin/"

#simulator = "bin/mips_simulator"
parser_exists = exists(p_parser)
sim_exists = exists(simulator)
print("parser_exist: ",parser_exists )
print("sim exists: ", sim_exists)

if not exists(p_tests_binary):
    os.mkdir(p_tests_binary)

files = os.listdir(p_tests)
done_tst = 0
passed_tst = 0


for file_name in sorted(files):
    done_tst += 1
    #test_file = open(p_tests + file_name)
    with open(p_tests + file_name, 'rb') as test_file:
        TestId = test_file.readline()[8:-1]
        #TestId = TestId[0:-1]
        Instruction = test_file.readline()[13:-1]
        Author = test_file.readline()[8:-1]
        Expected_Exit = test_file.readline()[6:-1]
        Message =  test_file.readline()[9:-1]
        Status = "Fail"
        #print_file(TestId, Instruction, Author, Expected_Exit, Message);
        #print(p_tests_binary + TestId ,exists(p_tests_binary + TestId))

        create_bin(test_file, TestId, p_parser, p_tests_binary)#
        print(exists(p_tests_binary + TestId + '.mips.bin'))
        if(exists(p_tests_binary + TestId + '.mips.bin')):#
            exit = sps.call([simulator, p_tests_binary + TestId + '.mips.bin'], stderr=sps.PIPE)#
            #print(p_tests_binary + TestId + '.mips.bin')
            if (int(Expected_Exit) == exit):
                Status = "Pass"
                passed_tst += 1
        #print(TestId + ", " + Instruction + ", " + Status + ", " + Author + ", " + Message)
        test_file.close()
print("passed %d/%d tests" %(passed_tst, done_tst))
rm(p_tests_binary)
