lui $20, 0x2001

lui $10, 0x1122
addiu $10, $10, 0x3344
sw $10, 0x0($20)

lui $12, 0x248A
addiu $12, $0, 0x1379
add $13, $0, $12

lwr $13, 0x1($20)

srl $22, $12, 16
srl $23, $13, 16

beq $22, $23, pass

addiu $2, $0, 11
jr $0
nop

pass: addiu $2, $0, 2
jr $0
