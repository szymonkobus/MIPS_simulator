lui $10, 0xFFFF
sll $15, $10, 16
beq $15, $0, pass

nop
jr $0

pass: addiu $2, $0, 1
jr $0
