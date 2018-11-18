lui $20, 0x2000    #base

lbu $25, 0x0($20)
nop
beq $25, $0, pass1
addu $2, $0, $25
jr $0

pass1: lui $20, 0x2300     #base

lbu $26, 0x1($20)
nop
beq $26, $0, pass2
addu $2, $0, $26
jr $0

pass2: lui $20, 0x23FF     #base
addi $20, $20, 0x7FFF
addi $20, $20, 0x7FFF

lbu $27, 0x1($20)
nop
beq $27, $0, pass3
addu $2, $0, $27
jr $0

nop

pass3: addiu $2, $0, 0x1
jr $0
