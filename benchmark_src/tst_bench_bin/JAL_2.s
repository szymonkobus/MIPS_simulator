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
jal 8
nop
jr $0
