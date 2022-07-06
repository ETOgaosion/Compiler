iobuff:
	.zero 80
.text
.align 1
.globl	add
.type	add, @function
add:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	lw	t0, -12(sp)
	addi	t1, zero, 2
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -24(sp)
	lb	t0, -24(sp)
	beqz	t0, L_0_add
	lw	t0, -12(sp)
	addi	t1, zero, 2
	mulw	t2, t0, t1
	sw	t2, -20(sp)
	lw	a0, -20(sp)
	ld	ra, -8(sp)
	ret
	lla	t0, L_1_add
	jr	t0
L_0_add:
	lw	t1, -12(sp)
	addi	t0, t1, 10
	sw	t0, -16(sp)
	lw	a0, -16(sp)
	ld	ra, -8(sp)
	ret
L_1_add:
	ld	ra, -8(sp)
	ret
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
	addi	sp, sp, -56
	call	get_int
	addi	sp, sp, 56
	sw	a0, -48(sp)
	lw	t0, -48(sp)
	sw	t0, -16(sp)
	lw	t0, -16(sp)
	addi	t1, zero, 1
	slt	t2, t1, t0
	sb	t2, -32(sp)
	lb	t0, -32(sp)
	beqz	t0, L_0_main
	lw	a0, -16(sp)
	addi	sp, sp, -56
	call	add
	addi	sp, sp, 56
	sw	a0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	addi	t0, zero, 2
	addi	t1, zero, 8
	mulw	t2, t0, t1
	sw	t2, -52(sp)
	lw	t1, -52(sp)
	addi	t0, t1, 1
	sw	t0, -40(sp)
	lw	t1, -40(sp)
	addi	t0, t1, 100
	sw	t0, -44(sp)
	lw	t0, -44(sp)
	li	t1, 9999
	subw	t2, t0, t1
	sw	t2, -28(sp)
	li	t0, 10000
	addi	t1, zero, 5
	divw	t2, t0, t1
	sw	t2, -56(sp)
	lw	t1, -28(sp)
	lw	t2, -56(sp)
	addw	t0, t1, t2
	sw	t0, -36(sp)
	lw	t0, -36(sp)
	sw	t0, -12(sp)
	lw	t1, -12(sp)
	addi	t0, t1, 1000
	sw	t0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
L_1_main:
	lw	a0, -12(sp)
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	mv	a0, zero
	ld	ra, -8(sp)
	ret
