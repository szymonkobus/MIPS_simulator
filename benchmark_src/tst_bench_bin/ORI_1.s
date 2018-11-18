addi $2, $2, 0x5432
ori $2, $2, 0xABCD
ori $3, $3, 0xFFFF
beq $2, $3, pass
nop
jr $0
addi $2, $0, 0x45
pass: addi $2, $2, 0x3
jr $0
nop
