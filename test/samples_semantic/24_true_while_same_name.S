iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	t0, zero
	sw	t0, -16(sp)
	mv	t0, zero
	sw	t0, -12(sp)
L_1_main:
	lw	t0, -16(sp)
	addi	t1, zero, 3
	slt	t2, t0, t1
	sb	t2, -24(sp)
	lb	t0, -24(sp)
	beqz	t0, L_0_main
	lw	t0, -16(sp)
	addi	t1, zero, 1
	addw	t2, t0, t1
	sw	t2, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -32(sp)
	lw	t0, -12(sp)
	addi	t1, zero, 1
	addw	t2, t0, t1
	sw	t2, -36(sp)
	lw	t0, -36(sp)
	sw	t0, -20(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	ld	a0, -12(sp)
	ld	ra, -8(sp)
	ret
