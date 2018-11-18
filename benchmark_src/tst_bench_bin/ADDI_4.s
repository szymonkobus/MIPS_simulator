addi $10, $0, 0x7FFF      #0x00007FFF
sll $11, $10, 16          #0x7FFF0000
add $12, $11, $10         #0x7FFF7FFF
addi $13, $12, 0x7FFF     #0x7FFFFFFE
addi $14, $13, 0x2        #0x80000000
jr $0
