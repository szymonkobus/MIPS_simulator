lui $20, 0x2000
addiu $20, $20, 4

lui  $5, 0x0102
addiu $5, $5, 0x0304

srl $6, $5, 16

sh $5, 0xFFFE($20)
sh $6, 0xFFFC($20)

addiu $20, $20, -4
lw $10, 0x0($20)

lui $11, 0x0102
addiu $11, $11, 0x0304

beq $10, $11, pass
addiu $2, $0, 3
jr $0

nop
pass: addiu $2, $0, 5
jr $0
