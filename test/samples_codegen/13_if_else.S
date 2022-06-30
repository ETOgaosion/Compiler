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
	addi	t0, zero, 2
	sw	t0, -12(sp)
	addi	sp, sp, -24
	call	get_int
	addi	sp, sp, 24
	sw	a0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	lw	t0, -16(sp)
	mv	t1, zero
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -24(sp)
	lb	t0, -24(sp)
	beqz	t0, L_0_main
	addi	t0, zero, 4
	sw	t0, 0(sp)
	lw	t0, -16(sp)
	sw	t0, -12(sp)
	lw	a0, -12(sp)
	addi	sp, sp, -24
	call	print_int
	addi	sp, sp, 24
L_0_main:
	addi	t0, zero, 2
	sw	t0, 0(sp)
	lw	t0, -12(sp)
	sw	t0, -16(sp)
	lw	a0, -16(sp)
	addi	sp, sp, -24
	call	print_int
	addi	sp, sp, 24
	mv	a0, zero
	ld	ra, -8(sp)
	ret
