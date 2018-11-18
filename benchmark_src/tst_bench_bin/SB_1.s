lui $20, 0x2000

lui $10, 0x1234
addiu $10, $10, 0x5678

srl $11, $10, 8
srl $12, $10, 16
srl $13, $10, 24

sb $13, 0x0($20)
sb $12, 0x1($20)
sb $11, 0x2($20)
sb $10, 0x3($20)

lw $19, 0x0($20)
nop

beq $19, $10, pass
addiu $2, $0, 0
jr $0

nop
pass: addiu $2, $0, 1
jr $0
