.data
str1: .asciiz "The sum of the two constants in decimal is = "

.text
.globl main

main:

add		$t1, $zero, 0x2A		# $t1 = zero1 + 0x2A
add		$t2, $zero, 0x0D		# $t1 = zero1 + 0x0D
add		$s3, $t1, $t2		    # $s3 = $t1 + $t2

li      $v0, 4
la      $a0, str1
syscall

li      $v0,1
move    $a0, $s3
syscall

li      $v0,10
syscall