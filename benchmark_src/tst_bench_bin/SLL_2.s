addiu $2, $0, 10
lui $5, 0xDACF
addiu $5, $5, 0xFFFF
sll $7, $5, 31
lui $6, 0x8000
beq $6, $7, pass

addiu $2, $0, 5
jr $0

nop
pass: addiu $2, $0, 18
jr $0
