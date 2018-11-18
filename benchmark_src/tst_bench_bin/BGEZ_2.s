addiu $21, $0, -10
bgez $21, end
nop

jr $0
addiu $2, $0, -100

end: addiu $2, $0, 100
jr $0
