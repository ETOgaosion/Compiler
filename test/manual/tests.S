.text
.align 1
.globl	main
.type	main, @function
main:
L_1_main:
	lw	t0, -20(sp)
	addi	t1, zero, 10
	slt	t2, t0, t1
	sb	t2, -36(sp)
	lb	t0, -36(sp)
	beqz	t0, L_0_main
L_3_main:
	lw	t0, -16(sp)
	addi	t1, zero, 5
	slt	t2, t0, t1
	sb	t2, -32(sp)
	lb	t0, -32(sp)
	beqz	t0, L_2_main
	lw	t0, -20(sp)
	sw	t0, -12(sp)
	lw	t1, -16(sp)
	addi	t0, t1, 1
	sw	t0, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -16(sp)
	lla	t0, L_3_main
	jr	t0
L_2_main:
	lw	t1, -20(sp)
	addi	t0, t1, 2
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -20(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	lw	a0, -12(sp)
	addi	sp, sp, -40
	call	print_int
	addi	sp, sp, 40
	mv	a0, zero
	ret
