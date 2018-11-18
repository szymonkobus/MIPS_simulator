beq $0, $0, test
nop
addiu $2, $0, 3
jr $0

nop
nop
nop
nop
nop
nop
nop
nop
nop
nop

test: addiu $2, $0, 7
lui $15, 0x1000
addiu $15, $15, 8
jalr $26, $15
nop

jr $0
