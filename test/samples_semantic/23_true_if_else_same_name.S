iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 3
	sw	t0, -16(sp)
	addi	t0, zero, 2
	sw	t0, -12(sp)
	lw	t0, -16(sp)
	mv	t1, zero
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -28(sp)
	lb	t0, -28(sp)
	beqz	t0, L_0_main
	addi	t0, zero, 4
	sw	t0, 0(sp)
	lw	t0, -16(sp)
	sw	t0, -24(sp)
L_0_main:
	addi	t0, zero, 2
	sw	t0, 0(sp)
	lw	t0, -12(sp)
	sw	t0, -20(sp)
	ld	a0, -16(sp)
	ld	ra, -8(sp)
	ret
