.data
num: .word 0
msg: .asciiz "Enter the Number: "
msg1: .asciiz "Palindrome"
msg2: .asciiz "Not Palindrome"
.text
.globl main

main:
        li $v0,4     
        la $a0, msg
        syscall
        li $v0,5
        syscall

        move $t0, $v0  # $t0 = $v0
        move $t3, $t0  # $t3 = $t0
        li $t2, 0      # $t2 = 0
loop:
        mul $t2, $t2, 10
        rem $t1,$t0,10
        div $t0,$t0,10
        add $t2, $t2, $t1
        bne $t0, $zero ,loop
        bne $t3, $t2, np
        li $v0, 4
        la $a0, msg1
        syscall
        li $v0, 10
        syscall
np:
        li $v0, 4
        la $a0, msg2
        syscall
        li $v0, 10
        syscall