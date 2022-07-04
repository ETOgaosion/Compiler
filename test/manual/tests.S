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
	addi	t5, zero, 5
	lla	t6, a
	sw	t5, 0(t6)
	mv	t5, zero
	mv	t4, t5
L_1_main:
	lla	t6, a
	lw	t5, 0(t6)
	addi	t6, zero, 6
	slt	t1, t5, t6
	mv	t5, zero
	xor	t6, t4, t5
	seqz	t3, t6
	or	t0, t1, t3
	beqz	t0, L_0_main
	lla	t6, a
	lw	t5, 0(t6)
	addi	t2, t5, 1
	lla	t5, a
	sw	t2, 0(t5)
	addi	t1, t4, 1
	mv	t4, t1
	lla	t5, L_1_main
	jr	t5
L_0_main:
	mv	a0, t4
	sw	t0, -28(sp)
	sw	t1, -16(sp)
	sw	t2, -32(sp)
	sw	t3, -24(sp)
	sw	t4, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	t0, -28(sp)
	lw	t1, -16(sp)
	lw	t2, -32(sp)
	lw	t3, -24(sp)
	lw	t4, -12(sp)
	addi	a0, zero, 8
	sw	t0, -28(sp)
	sw	t1, -16(sp)
	sw	t2, -32(sp)
	sw	t3, -24(sp)
	sw	t4, -12(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	t0, -28(sp)
	lw	t1, -16(sp)
	lw	t2, -32(sp)
	lw	t3, -24(sp)
	lw	t4, -12(sp)
	mv	a0, t4
	ld	ra, -8(sp)
	ret
