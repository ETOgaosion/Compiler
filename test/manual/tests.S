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
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -16(sp)
	lw	a0, -16(sp)
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
	sb	t2, -20(sp)
	lw	t0, -12(sp)
	mv	t1, zero
	xor	t2, t0, t1
	seqz	t3, t2
	sb	t3, -24(sp)
	lb	t0, -20(sp)
	lb	t1, -24(sp)
	or	t2, t0, t1
	sb	t2, -28(sp)
	lb	t0, -28(sp)
	beqz	t0, L_0_main
	lla	t1, a
	addi	t0, t1, 1
	sw	t0, -32(sp)
	lw	t0, -32(sp)
	lla	t1, a
	sw	t0, 0(t1)
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -16(sp)
	lw	t0, -16(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	lw	a0, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	addi	a0, zero, 8
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	a0, -12(sp)
	ld	ra, -8(sp)
	ret
