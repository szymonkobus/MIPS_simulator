addiu $21, $0, -1
addiu $31, $0, 5
bgezal $21, procedure
nop
add $2, $31, $0
jr $0
nop

procedure: addiu $2, $0, 10
jr $0
