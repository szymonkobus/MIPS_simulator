addi $10, $0, -1
addi $11, $0, 1
mult $10, $11

nop
nop
nop

mfhi $26
beq $26, $10, pass1
add $2, $0, $0
jr $0

pass1: mflo $25
beq $25, $10, pass2
add $2, $0, $0
jr $0

nop
pass2: addiu $2, $0, 19
jr $0
