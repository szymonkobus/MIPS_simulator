# 0x3456 * 0x76543210 = 0x1830 DA74 1160
addiu $10, $0, 0x3456
lui $11, 0x7654
addi $11, $11, 0x3210
mult $10, $11
lui $15, 0xDA74
addi $15, $15, 0x1160
addi $16, $0, 0x1830
mfhi $26
beq $26, $16, pass
add $2, $0, $0
jr $0
nop
pass: addiu $2, $0, 17
jr $0
