addiu $21, $0, 10
bgezal $21, procedure
addiu $2, $2, 1
addiu $2, $2, 1
addiu $2, $2, 1
jr $0
nop

procedure: addu $2, $0, $31
jr $0
