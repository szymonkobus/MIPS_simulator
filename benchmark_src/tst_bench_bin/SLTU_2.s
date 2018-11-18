addi $3, $3, 0xFEAB
sltu $2, $3, $3
bgtz $2, fail
addi $2, $0, 5
jr $0
nop

fail: addi $2, $0, 3
jr $0
