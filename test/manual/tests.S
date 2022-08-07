.text
.align 1
.globl	main
.type	main, @function
main:
L_1_main:
	lw	t0, -20(sp)
	addi	t1, zero, 10
	slt	t2, t0, t1
	sb	t2, -28(sp)
	lw	t0, -16(sp)
	addi	t1, zero, 1
	slt	t2, t0, t1
	sb	t2, -36(sp)
	lb	t0, -28(sp)
	lb	t1, -36(sp)
	and	t2, t0, t1
	sb	t2, -40(sp)
	lb	t0, -40(sp)
	beqz	t0, L_0_main
	lw	t0, -20(sp)
	addi	t1, zero, 5
	slt	t2, t0, t1
	sb	t2, -44(sp)
	lb	t0, -44(sp)
	beqz	t0, L_2_main
	lw	t1, -20(sp)
	addi	t0, t1, 2
	sw	t0, -48(sp)
	lw	t0, -48(sp)
	sw	t0, -16(sp)
	lw	a0, -20(sp)
	lw	a0, -16(sp)
	addi	sp, sp, -56
	call	add_int
	addi	sp, sp, 56
	sw	a0, -52(sp)
	lla	t0, L_3_main
	jr	t0
L_2_main:
L_3_main:
	lw	t1, -20(sp)
	addi	t0, t1, 2
	sw	t0, -32(sp)
	lw	t0, -32(sp)
	sw	t0, -20(sp)
	lw	t1, -16(sp)
	addi	t0, t1, 1
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -16(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	mv	a0, zero
	ret
.text
.align 1
.globl	add_int
.type	add_int, @function
add_int:
	sw	a0, -16(sp)
	sw	a0, -12(sp)
	lw	t1, -16(sp)
	lw	t2, -12(sp)
	addw	t0, t1, t2
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -20(sp)
	lw	a0, -20(sp)
	ret
