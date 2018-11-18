addiu $20, $0, 10
addiu $21, $0, -11
subu $10, $20, $21

addiu $11, $0, 21

beq $11, $10, pass

addiu $2, $0, 4
jr $0

nop

pass: addiu $2, $0, 56
jr $0
