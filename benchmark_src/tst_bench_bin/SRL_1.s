addiu $5, $0, -1
srl $6, $5, 1
beq $6, $5, fail
addiu $2, $0, 11
jr $0

nop

fail: addiu $2, $0, 3
jr $0
