lui $20, 0x2000

addiu $10, $0, 0x1234
addiu $11, $10, 0x5678

sh $10, 0x0($20)
sh $11, 0x2($20)

lw $19, 0x0($20)

sll $12, $10, 16
add $12, $12, $11

beq $19, $12, pass
addiu $2, $0, 1
jr $0

nop
pass: addiu $2, $0, 3
jr $0
