iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 4
	sw	t0, -20(sp)
	mv	t0, zero
	sw	t0, -16(sp)
	mv	t0, zero
	sw	t0, -12(sp)
	addi	sp, sp, -40
	call	get_int
	addi	sp, sp, 40
	sw	a0, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -12(sp)
L_1_main:
	lw	t0, -16(sp)
	lw	t1, -20(sp)
	slt	t2, t0, t1
	sb	t2, -32(sp)
	lb	t0, -32(sp)
	beqz	t0, L_0_main
	lw	t1, -16(sp)
	addi	t0, t1, 1
	sw	t0, -36(sp)
	lw	t0, -36(sp)
	sw	t0, -16(sp)
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -12(sp)
	lw	a0, -12(sp)
	addi	sp, sp, -40
	call	print_int
	addi	sp, sp, 40
	lla	t0, L_1_main
	jr	t0
L_0_main:
	mv	a0, zero
	ld	ra, -8(sp)
	ret
