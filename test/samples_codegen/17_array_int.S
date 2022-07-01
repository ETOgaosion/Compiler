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
.globl	int_array_add
.type	int_array_add, @function
int_array_add:
	sd	ra, -8(sp)
	lla	t0, ImmValue_2
	lla	t1, 
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
	sw	t0, 0(t1)
	mv	t0, zero
	sw	t0, -12(sp)
L_1_int_array_add:
	lw	t0, -12(sp)
	lla	t1, n
	slt	t2, t0, t1
	sb	t2, -28(sp)
	lb	t0, -28(sp)
	beqz	t0, L_0_int_array_add
	lw	t1, -12(sp)
	lla	t0, int_array_a
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -32(sp)
	lw	t1, -12(sp)
	lla	t0, int_array_b
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -36(sp)
	lw	t1, -32(sp)
	lw	t2, -36(sp)
	addw	t0, t1, t2
	sw	t0, -40(sp)
	lw	t1, -12(sp)
	lw	t2, -40(sp)
	lla	t0, int_array_c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	lw	t1, -12(sp)
	lla	t0, int_array_c
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	lw	a0, -24(sp)
	addi	sp, sp, -40
	call	print_int
	addi	sp, sp, 40
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_int_array_add
	jr	t0
L_0_int_array_add:
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -8
	call	int_array_add
	addi	sp, sp, 8
	mv	a0, zero
	ld	ra, -8(sp)
	ret
