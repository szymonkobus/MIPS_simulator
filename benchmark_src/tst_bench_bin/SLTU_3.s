addi $3, $0, -1
addi $4, $0, -2
sltu $2, $4, $3
bgtz $2, pass
addi $2, $0, 11
jr $0
nop

pass: addi $2, $0, 13
jr $0
