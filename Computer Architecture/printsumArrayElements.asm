.data
    num: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    str1: .asciiz "The sum of the 10 numbers is = "
.text
.globl main
main:
        la      $t0, num
        li      $t2, 0 # hold the sum
        li      $t3, 0 # counter for loop

loop:   lw      $t1, 0($t0)
        add     $t2, $t2, $t1
        addi    $t3, $t3, 1
        addi    $t0, $t0, 4 # point to next
        bne     $t3, 10, loop

        li      $v0, 4
        la      $a0, str1
        syscall

        li      $v0,1
        move    $a0, $t2
        syscall
        
        li      $v0,10
        syscall