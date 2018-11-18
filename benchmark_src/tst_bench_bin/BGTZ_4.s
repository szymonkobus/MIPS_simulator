beq $0, $0 prog
nop

end: addiu $2, $2, 5
jr $0
nop

prog: addiu $21, $0, 10
bgtz $21, end
nop

jr $0
addiu $2, $0, -7
