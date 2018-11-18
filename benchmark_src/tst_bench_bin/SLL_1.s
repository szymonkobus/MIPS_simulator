addiu $5, $0, -1
sll $6, $5, 1
addiu $7, $0, -2
beq $6, $7, pass

addiu $2, $0, 3
jr $0
nop

pass: addiu $2, $0, 12
jr $0
