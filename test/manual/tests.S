.text
.align 1
.globl	main
.type	main, @function
main:
	li	a0, -7882
	addi	sp, sp, -64
	call	print_int
	addi	sp, sp, 64
	lla	t0, L_2_main
	jr	t0
L_2_main:
L_3_main:
	lw	a0, -16(sp)
	addi	sp, sp, -64
	call	print_int
	addi	sp, sp, 64
L_1_main:
	lw	a0, -16(sp)
	addi	sp, sp, -64
	call	print_int
	addi	sp, sp, 64
	mv	a0, zero
	ret
