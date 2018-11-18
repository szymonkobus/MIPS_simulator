addiu $10, $0, -1
addiu $11, $0, 2
multu $10, $11
nop
nop
mflo $4
multu $4, $11
addiu $2, $0, 0x7
jr $0
