iobuff:
	.zero 80
.data
.globl	double_array_b
.type	double_array_b, @object
double_array_b:
	.word	0x401f333333333333
	.word	0x4021cccccccccccd
	.word	0x4022333333333333
	.word	0x4024666666666666
	.word	0x402699999999999a
	.word	0x4028cccccccccccd

.data
.globl	n
.type	n, @object
n:
	.word	0x6

.data
.globl	double_array_a
.type	double_array_a, @object
double_array_a:
	.word	0x3ff3333333333333
	.word	0x4002666666666666
	.word	0x400b333333333333
	.word	0x4012000000000000
	.word	0x4016666666666666
	.word	0x401acccccccccccd

ImmValue_2:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

.text
.align 1
.globl	double_array_add
.type	double_array_add, @function
double_array_add:
	sd	ra, -8(sp)
	lla	t0, ImmValue_2
	lla	t1, 
	addi	t1, t1, 4
	sd	t0, 0(t1)
	addi	t1, t1, 4
	sd	t0, 0(t1)
	addi	t1, t1, 4
	sd	t0, 0(t1)
	addi	t1, t1, 4
	sd	t0, 0(t1)
	addi	t1, t1, 4
	sd	t0, 0(t1)
	addi	t1, t1, 4
	sd	t0, 0(t1)
	mv	t0, zero
	sw	t0, -12(sp)
L_1_double_array_add:
	lw	t0, -12(sp)
	lla	t1, n
	slt	t2, t0, t1
	sb	t2, -36(sp)
	lb	t0, -36(sp)
	beqz	t0, L_0_double_array_add
	lw	t1, -12(sp)
	lla	t0, double_array_a
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -44(sp)
	lw	t1, -12(sp)
	lla	t0, double_array_b
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -52(sp)
	fld	ft0, -44(sp)
	fld	ft0, -52(sp)
	fadd.d	ft0, ft0, ft0
	fsd	ft0, -60(sp)
	lw	t0, -12(sp)
	fld	ft0, -60(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	lw	t1, -12(sp)
	lla	t0, double_array_c
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	fld	fa0, -32(sp)
	addi	sp, sp, -64
	call	print_double
	addi	sp, sp, 64
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -12(sp)
	lla	t0, L_1_double_array_add
	jr	t0
L_0_double_array_add:
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -8
	call	double_array_add
	addi	sp, sp, 8
	mv	a0, zero
	ld	ra, -8(sp)
	ret
