.text
.align 1
.globl	main
.type	main, @function
main:
L_1_main:
	lw	t0, -16(sp)
	addi	t1, zero, 10
	slt	t2, t0, t1
	sb	t2, -24(sp)
	lb	t0, -24(sp)
	beqz	t0, L_0_main
	lw	t1, -16(sp)
	addi	t0, t1, 1
	sw	t0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	lw	a0, -16(sp)
	addi	sp, sp, -24
	call	print_int
	addi	sp, sp, 24
	mv	a0, zero
	ret
