iobuff:
	.zero 80
.text
.align 1
.globl	fibonacci
.type	fibonacci, @function
fibonacci:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	mv	t0, zero
	sw	t0, -28(sp)
	addi	t0, zero, 1
	sw	t0, -24(sp)
	mv	t0, zero
	sw	t0, -20(sp)
	mv	t0, zero
	sw	t0, -16(sp)
L_1_fibonacci:
	lw	t0, -20(sp)
	lw	t1, -12(sp)
	slt	t2, t0, t1
	sb	t2, -36(sp)
	lb	t0, -36(sp)
	beqz	t0, L_0_fibonacci
	lw	t1, -28(sp)
	lw	t2, -24(sp)
	addw	t0, t1, t2
	sw	t0, -40(sp)
	lw	t0, -40(sp)
	sw	t0, -16(sp)
	lw	a0, -16(sp)
	addi	sp, sp, -40
	call	print_int
	addi	sp, sp, 40
	lw	t0, -24(sp)
	sw	t0, -28(sp)
	lw	t0, -16(sp)
	sw	t0, -24(sp)
	lw	t1, -20(sp)
	addi	t0, t1, 1
	sw	t0, -32(sp)
	lw	t0, -32(sp)
	sw	t0, -20(sp)
	lla	t0, L_1_fibonacci
	jr	t0
L_0_fibonacci:
	lw	a0, -16(sp)
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	t0, zero
	sw	t0, -12(sp)
	addi	sp, sp, -24
	call	get_int
	addi	sp, sp, 24
	sw	a0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -12(sp)
	lw	a0, -12(sp)
	addi	sp, sp, -24
	call	fibonacci
	addi	sp, sp, 24
	sw	a0, -16(sp)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
