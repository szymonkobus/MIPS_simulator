addiu $21, $0, 2
addiu $22, $0, 2
beq $22, $21, end
nop

jr $0
addiu $2, $0, 8

end: addiu $2, $0, 5
jr $0
