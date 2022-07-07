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
	beqz	t0, L_0_main
	lla	t0, L_1_main
	jr	t0
L_0_main:
L_1_main:
	mv	a0, zero
	ld	ra, -8(sp)
	ret
