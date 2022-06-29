iobuff:
	.zero 80
.data
.globl	m
.type	m, @object
m:
	.word	0x3f800000
	.word	0x40000000
	.word	0x40400000
	.word	0x40800000

.data
.globl	a
.type	a, @object
a:
	.word	0x2

.text
.align 1
.globl	fun
.type	fun, @function
fun:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	lw	t0, -12(sp)
	addi	t1, zero, 1
	addw	t2, t0, t1
	sw	t2, -16(sp)
	ld	a0, -16(sp)
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 5
	lla	t1, a
	sw	t0, 0(t1)
	mv	t0, zero
	sw	t0, -12(sp)
L_1_main:
	lla	t0, a
	addi	t1, zero, 6
	slt	t2, t0, t1
	sb	t2, -72(sp)
	lw	t0, -12(sp)
	mv	t1, zero
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -52(sp)
	lb	t0, -72(sp)
	lb	t1, -52(sp)
	or	t2, t0, t1
	sb	t2, -48(sp)
	lb	t0, -48(sp)
	beqz	t0, L_0_main
	lla	t0, a
	lw	t1, -12(sp)
	addw	t2, t0, t1
	sw	t2, -40(sp)
	lw	t0, -40(sp)
	addi	t1, zero, 10
	slt	t2, t0, t1
	not	t2, t2
	sb	t2, -56(sp)
	lla	t0, a
	lw	t1, -12(sp)
	mulw	t2, t0, t1
	sw	t2, -76(sp)
	lw	t0, -76(sp)
	addi	t1, zero, 10
	remw	t2, t0, t1
	sw	t2, -64(sp)
	lw	t0, -64(sp)
	mv	t1, zero
	xor	t2, t0, t1
	snez	t3, t2
	sb	t3, -68(sp)
	lb	t0, -56(sp)
	lb	t1, -68(sp)
	and	t2, t0, t1
	sb	t2, -44(sp)
	lb	t0, -44(sp)
	beqz	t0, L_2_main
	lla	t0, L_0_main
	jr	t0
L_2_main:
	lla	t0, a
	addi	t1, zero, 2
	mulw	t2, t0, t1
	sw	t2, -80(sp)
	lw	t0, -80(sp)
	addi	t1, zero, 10
	addw	t2, t0, t1
	sw	t2, -60(sp)
	lw	t0, -60(sp)
	addi	t1, zero, 12
	addw	t2, t0, t1
	sw	t2, -36(sp)
	addi	a0, zero, 5
	addi	t0, zero, 16
	subw	sp, sp, t0
	call	fun
	sw	a0, -32(sp)
	lw	t0, -36(sp)
	lw	t1, -32(sp)
	addw	t2, t0, t1
	sw	t2, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -24(sp)
	lla	t0, a
	addi	t1, zero, 1
	addw	t2, t0, t1
	sw	t2, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	ld	a0, -12(sp)
	addi	t0, zero, 8
	subw	sp, sp, t0
	call	print_int
	ld	a0, -12(sp)
	ld	ra, -8(sp)
	ret
