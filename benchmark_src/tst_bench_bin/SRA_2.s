addiu $2, $0, 10
lui $5, 0xFACE
addiu $5, $0, 0xB00C
sra $6, $5, 31

addiu $10, $0, -1
beq $10, $6, pass

addiu $2, $0, 23
jr $0
nop

pass: addiu $2, $0, 17
jr $0
