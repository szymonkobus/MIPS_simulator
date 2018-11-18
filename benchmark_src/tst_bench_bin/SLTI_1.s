addi $3, $0, -1
slti $4, $3, 1
bgtz $4, pass
addi $2, $0, 5
jr $0
nop

pass: addi $2, $0, 7
jr $0
