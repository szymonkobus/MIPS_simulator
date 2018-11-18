lui $20, 0x208F     #base

lui $10, 0xFF44
addiu $10, $10, 0x88AA
sw $10, 0x0($20)

addiu $4, $0, 0x12
lwl $4, 0x1($20)
nop

addu $2, $0, $4
jr $0
