iobuff:
	.zero 80
.data
.globl	double_array_b
.type	double_array_b, @object
double_array_b:
	.quad	0x401f333333333333
	.quad	0x4021cccccccccccd
	.quad	0x4022333333333333
	.quad	0x4024666666666666
	.quad	0x402699999999999a
	.quad	0x4028cccccccccccd

.data
.globl	n
.type	n, @object
n:
	.word	0x6

.data
.globl	double_array_a
.type	double_array_a, @object
double_array_a:
	.quad	0x3ff3333333333333
	.quad	0x4002666666666666
	.quad	0x400b333333333333
	.quad	0x4012000000000000
	.quad	0x4016666666666666
	.quad	0x401acccccccccccd

ImmValue_2:
	.quad	0x0
	.quad	0x0
	.quad	0x0
	.quad	0x0
	.quad	0x0
	.quad	0x0

.text
.align 1
.globl	double_array_vector_add
.type	double_array_vector_add, @function
double_array_vector_add:
	sd	ra, -8(sp)
	lla	t0, ImmValue_2
	addi	t1, sp, -56
	sd	t0, 0(t1)
	addi	t1, t1, 8
	sd	t0, 0(t1)
	addi	t1, t1, 8
	sd	t0, 0(t1)
	addi	t1, t1, 8
	sd	t0, 0(t1)
	addi	t1, t1, 8
	sd	t0, 0(t1)
	addi	t1, t1, 8
	sd	t0, 0(t1)
	addi	t1, t1, 8
	mv	t0, zero
	sd	t0, -76(sp)
L_0_double_array_vector_add:
	lla	t0, double_array_a
	ld	t1, -76(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -84(sp)
	lla	t0, double_array_b
	ld	t1, -76(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -92(sp)
	fld	ft0, -84(sp)
	fld	ft1, -92(sp)
	fadd.d	ft2, ft0, ft1
	fsd	ft2, -100(sp)
	addi	t0, sp, -56
	ld	t1, -76(sp)
	ld	t2, -100(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t1, -76(sp)
	addi	t0, t1, 1
	sd	t0, -76(sp)
	ld	t0, -76(sp)
	addi	t1, zero, 6
	slt	t2, t0, t1
	seqz	t2, t2
	sw	t2, -68(sp)
	lw	t0, -68(sp)
	beqz	t0, L_0_double_array_vector_add
	addi	t0, sp, -56
	addi	t1, zero, 5
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -64(sp)
	fld	fa0, -64(sp)
	addi	sp, sp, -104
	call	print_double
	addi	sp, sp, 104
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -8
	call	double_array_vector_add
	addi	sp, sp, 8
	mv	a0, zero
	ld	ra, -8(sp)
	ret
