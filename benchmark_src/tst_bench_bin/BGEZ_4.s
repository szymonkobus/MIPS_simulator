beq $0, $0 prog
nop

end: addiu $2, $2, 10
jr $0

prog: addiu $21, $0, 10
bgez $21, end
nop

jr $0
addiu $2, $0, -7
