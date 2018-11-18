lui $20, 0x2200     #base

lui $10, 0x1234
addiu $10, $10, 0x5678
sw $10, 0x0($20)

lhu $25, 0x0($20)
addiu $15, $0, 0x1234
beq $25, $15, pass1
addu $2, $0, $25
jr $0

pass1: lhu $26, 0x2($20)
addiu $15, $0, 0x5678
beq $26, $15, pass2
addu $2, $0, $26
jr $0

nop

pass2: addiu $2, $0, 0x5
jr $0
