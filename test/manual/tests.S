.text
.align 1
.globl	main
.type	main, @function
main:
	mv	t0, zero
	sw	t0, -16(sp)
	mv	t0, zero
	sw	t0, -12(sp)
	lw	t0, -16(sp)
	addi	t1, zero, 1
	slt	t2, t1, t0
	sb	t2, -48(sp)
	lb	t0, -48(sp)
	beqz	t0, L_0_main
	addi	t0, zero, 999
	addi	t1, zero, 2000
	mulw	t2, t0, t1
	sw	t2, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	addi	t0, zero, 2
	addi	t1, zero, 8
	mulw	t2, t0, t1
	sw	t2, -20(sp)
	lw	t1, -20(sp)
	addi	t0, t1, 1
	sw	t0, -32(sp)
	lw	t1, -32(sp)
	addi	t0, t1, 100
	sw	t0, -52(sp)
	lw	t0, -52(sp)
	li	t1, 9999
	subw	t2, t0, t1
	sw	t2, -40(sp)
	li	t0, 10000
	addi	t1, zero, 5
	divw	t2, t0, t1
	sw	t2, -44(sp)
	lw	t1, -40(sp)
	lw	t2, -44(sp)
	addw	t0, t1, t2
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -12(sp)
	lw	t1, -12(sp)
	addi	t0, t1, 1000
	sw	t0, -36(sp)
	lw	t0, -36(sp)
	sw	t0, -16(sp)
L_1_main:
	mv	a0, zero
	ret
