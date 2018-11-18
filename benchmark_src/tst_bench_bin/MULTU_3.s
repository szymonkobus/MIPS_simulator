addi $10, $0, -1
addi $11, $0, 3
multu $10, $11

nop
nop
nop

mfhi $26
addiu $16, $0, 2
beq $26, $16, pass1
addi $2, $0, 1
jr $0

pass1: mflo $25
addiu $15, $0, -3
beq $25, $15, pass2
addi $2, $0, 2
jr $0

nop
pass2: addiu $2, $0, 13
jr $0
