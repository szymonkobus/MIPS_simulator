addi $3, $3, 0xFEAB
slt $2, $3, $3
bgtz $2, fail
addi $2, $0, 5
jr $0
nop

fail: addi $2, $0, 7
jr $0
