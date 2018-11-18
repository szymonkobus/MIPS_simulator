lui $20, 0x2200     #base

lui $10, 0x1234
addiu $10, $10, 0x5678
sw $10, 0x0($20)
nop

lw $25, 0x0($20)
nop
beq $25, $10, pass
addu $2, $0, $25
jr $0

nop

pass: addiu $2, $0, 0x5
jr $0
