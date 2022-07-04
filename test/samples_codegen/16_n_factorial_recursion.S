iobuff:
	.zero 80
.text
.align 1
.globl	factorial
.type	factorial, @function
factorial:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	lw	t0, -12(sp)
	addi	t1, zero, 1
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -28(sp)
	lb	t0, -28(sp)
	beqz	t0, L_0_factorial
	lw	a0, -12(sp)
	ld	ra, -8(sp)
	ret
	lla	t0, L_1_factorial
	jr	t0
L_0_factorial:
	lw	t0, -12(sp)
	addi	t1, zero, 1
	subw	t2, t0, t1
	sw	t2, -24(sp)
	lw	a0, -24(sp)
	addi	sp, sp, -32
	call	factorial
	addi	sp, sp, 32
	sw	a0, -20(sp)
	lw	t0, -12(sp)
	lw	t1, -20(sp)
	mulw	t2, t0, t1
	sw	t2, -16(sp)
	lw	a0, -16(sp)
	ld	ra, -8(sp)
	ret
L_1_factorial:
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
	addi	sp, sp, -32
	call	get_int
	addi	sp, sp, 32
	sw	a0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	lw	t0, -16(sp)
	addi	t1, zero, 1
	slt	t2, t1, t0
	sb	t2, -24(sp)
	lb	t0, -24(sp)
	beqz	t0, L_0_main
	lw	a0, -16(sp)
	addi	sp, sp, -32
	call	factorial
	addi	sp, sp, 32
	sw	a0, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	addi	t0, zero, 1
	sw	t0, -12(sp)
L_1_main:
	lw	a0, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	mv	a0, zero
	ld	ra, -8(sp)
	ret
