addiu $4, $0, 0xC

xori $6, $5, 0x5

addiu $7, $0, 0x9

beq $6, $7, pass
addiu $2, $0, 12
jr $0
nop

pass: addiu $2, $0, 23
jr $0
