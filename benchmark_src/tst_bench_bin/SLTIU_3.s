addi $3, $0, -2
sltiu $2, $3, -1
bgtz $2, pass
addi $2, $0, 11
jr $0
nop

pass: addi $2, $0, 13
jr $0
