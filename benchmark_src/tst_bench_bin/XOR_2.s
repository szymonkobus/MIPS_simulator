lui $4, 0x3547
addiu $4, $4, 0x8FAD
lui $5, 0xFDA4
addiu $5, $5, 0x5853

xor $6, $5, $4
xor $6, $6, $5

beq $6, $4, pass
addiu $2, $0, 22
jr $0
nop

pass: addiu $2, $0, 29
jr $0
