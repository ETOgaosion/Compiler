.text
.align 1
.globl	main
.type	main, @function
main:
	lla	t0, L_0_main
	jr	t0
	li	a0, 1998000
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	lla	t0, L_1_main
	jr	t0
L_0_main:
	li	a0, -7882
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	li	a0, -6882
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
L_1_main:
	lw	a0, -16(sp)
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	mv	a0, zero
	ret
