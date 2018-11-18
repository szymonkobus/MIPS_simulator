addi $3, $0, -1
addi $4, $0, 1
sltu $2, $3, $4
bgtz $2, fail
addi $2, $0, 5
jr $0
nop

fail: addi $2, $0, 3
jr $0
