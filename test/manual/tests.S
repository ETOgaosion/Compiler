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
	mv	t0, zero
	sb	t0, -48(sp)
	mv	t0, zero
	beqz	t0, L_0_main
	li	t0, 1998000
	sw	t0, -28(sp)
	li	t0, 1998000
	sw	t0, -12(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	addi	t0, zero, 16
	sw	t0, -20(sp)
	addi	t0, zero, 17
	sw	t0, -32(sp)
	addi	t0, zero, 117
	sw	t0, -52(sp)
	li	t0, -9882
	sw	t0, -40(sp)
	addi	t0, zero, 2000
	sw	t0, -44(sp)
	li	t0, -7882
	sw	t0, -24(sp)
	li	t0, -7882
	sw	t0, -12(sp)
	li	t0, -6882
	sw	t0, -36(sp)
	li	t0, -6882
	sw	t0, -16(sp)
L_1_main:
	mv	a0, zero
	ld	ra, -8(sp)
	ret
