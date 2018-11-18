addiu $5, $0, -1
sra $6, $5, 1
beq $6, $5, pass
addiu $2, $0, 11
jr $0

nop

pass: addiu $2, $0, 3
jr $0
