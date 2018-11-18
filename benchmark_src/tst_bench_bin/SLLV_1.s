addiu $4, $0, 1
addiu $5, $0, -1
sllv $6, $5, $4

addiu $10, $0, -2
beq $10, $6, pass
addiu $2, $0, 3
jr $0

nop

pass: addiu $2, $0, 7
jr $0
