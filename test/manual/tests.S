.text
.align 1
.globl	main
.type	main, @function
main:
	li	a0, -7882
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	li	a0, -6882
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	lw	a0, -16(sp)
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	mv	a0, zero
	ret
