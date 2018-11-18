addiu $21, $0, -1
addiu $22, $0, -1
beq $22, $21, end
addiu $2, $0, 10

jr $0
addiu $2, $0, 8

end: addiu $2, $2, 7
jr $0
