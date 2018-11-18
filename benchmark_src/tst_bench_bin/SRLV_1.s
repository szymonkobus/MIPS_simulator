addiu $4, $0, 1
addiu $5, $0, -1
srlv $6, $5, $4

lui $15, 0x8000
addiu $15, $15, -1

beq $6, $15, pass
addiu $2, $0, 11
jr $0

nop

pass: addiu $2, $0, 3
jr $0
