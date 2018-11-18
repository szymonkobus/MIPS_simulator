addi $3, $0, -1
addi $4, $0, 1
slt $2, $3, $4
bgtz $2, pass
addi $2, $0, 5
jr $0
nop

pass: addi $2, $0, 3
jr $0
