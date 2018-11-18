addiu $21, $0, 10
bgtz $21, end
nop

jr $0
addiu $2, $0, -11

end: addiu $2, $0, 11
jr $0
