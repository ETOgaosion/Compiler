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
	mv	t0, a0
	addi	t1, t0, 1
	mv	a0, t1
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
	mv	t6, t0
L_1_main:
	lla	t1, a
	lw	t0, 0(t1)
	addi	t1, zero, 6
	slt	t3, t0, t1
	mv	t0, zero
	xor	t1, t6, t0
	seqz	t5, t1
	or	t2, t3, t5
	beqz	t2, L_0_main
	lla	t1, a
	lw	t0, 0(t1)
	addi	t4, t0, 1
	lla	t0, a
	sw	t4, 0(t0)
	addi	t3, t6, 1
	mv	t6, t3
	lla	t0, L_1_main
	jr	t0
L_0_main:
	mv	a0, t6
	sw	t2, -28(sp)
	sw	t3, -16(sp)
	sw	t4, -32(sp)
	sw	t5, -24(sp)
	sw	t6, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	t2, -28(sp)
	lw	t3, -16(sp)
	lw	t4, -32(sp)
	lw	t5, -24(sp)
	lw	t6, -12(sp)
	addi	a0, zero, 8
	sw	t2, -28(sp)
	sw	t3, -16(sp)
	sw	t4, -32(sp)
	sw	t5, -24(sp)
	sw	t6, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	t2, -28(sp)
	lw	t3, -16(sp)
	lw	t4, -32(sp)
	lw	t5, -24(sp)
	lw	t6, -12(sp)
	mv	a0, t6
	ld	ra, -8(sp)
	ret
