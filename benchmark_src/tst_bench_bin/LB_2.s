lui $20, 0x2200     #base

#setting up memory
lui $10, 0x80A0
lui $11, 0xC0F0
srl $11, $11, 16
add $12, $11, $10
sw $12, 0x0($20)

lb $25, 0x0($20)
addiu $15, $0, 0xFF80
beq $25, $15, pass1
addu $2, $0, $25
jr $0

pass1: lb $26, 0x1($20)
addiu $15, $0, 0xFFA0
beq $26, $15, pass2
addu $2, $0, $26
jr $0

pass2: lb $27, 0x2($20)
addiu $15, $0, 0xFFC0
beq $27, $15, pass3
addu $2, $0, $27
jr $0

pass3: lb $28, 0x3($20)
addiu $15, $0, 0xFFF0
beq $28, $15 pass4
addu $2, $0, $28
jr $0

nop

pass4: addiu $2, $0, 0x5
jr $0
