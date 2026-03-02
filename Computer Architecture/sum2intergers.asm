.data
value: .word 50, 30, 0
str1: .asciiz "The sum of the two numbers is = "
.text
.globl main
main:
la $t0, value
lw $t1, 0($t0)
lw $t2, 4($t0)
add $t3, $t1, $t2
sw $t3, 8($t0)
li $v0, 4
la $a0, str1
syscall
li $v0,1
move $a0, $t3
syscall
li $v0, 10
syscall