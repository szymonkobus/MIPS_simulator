lui $20, 0xC000
lui $21, 0x4000

subu $10, $20, $21

lui $11, 0x8000

beq $11, $10, pass

addiu $2, $0, 4
jr $0

nop

pass: addiu $2, $0, 35
jr $0
