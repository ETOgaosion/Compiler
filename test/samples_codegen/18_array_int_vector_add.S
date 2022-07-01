iobuff:
	.zero 80
.data
.globl	n
.type	n, @object
n:
	.word	0x6

.data
.globl	int_array_b
.type	int_array_b, @object
int_array_b:
	.word	0x7
	.word	0x8
	.word	0x9
	.word	0xa
	.word	0xb
	.word	0xc

.data
.globl	int_array_a
.type	int_array_a, @object
int_array_a:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4
	.word	0x5
	.word	0x6

ImmValue_2:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

.text
.align 1
.globl	int_array_vector_add
.type	int_array_vector_add, @function
int_array_vector_add:
	sd	ra, -8(sp)
	lla	t0, ImmValue_2
	addi	t1, sp, -32
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	mv	t0, zero
	sw	t0, -44(sp)
L_0_int_array_vector_add:
	lla	t0, int_array_a
	lw	t1, -44(sp)
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -48(sp)
	lla	t0, int_array_b
	lw	t1, -44(sp)
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -52(sp)
	lw	t1, -48(sp)
	lw	t2, -52(sp)
	addw	t0, t1, t2
	sw	t0, -56(sp)
	addi	t0, sp, -32
	lw	t1, -44(sp)
	lw	t2, -56(sp)
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	lw	t1, -44(sp)
	addi	t0, t1, 1
	sw	t0, -44(sp)
	lw	t0, -44(sp)
	addi	t1, zero, 6
	slt	t2, t0, t1
	seqz	t2, t2
	sw	t2, -40(sp)
	lw	t0, -40(sp)
	beqz	t0, L_0_int_array_vector_add
	addi	t0, sp, -32
	addi	t1, zero, 5
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -36(sp)
	lw	a0, -36(sp)
	addi	sp, sp, -56
	call	print_int
	addi	sp, sp, 56
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -8
	call	int_array_vector_add
	addi	sp, sp, 8
	mv	a0, zero
	ld	ra, -8(sp)
	ret
