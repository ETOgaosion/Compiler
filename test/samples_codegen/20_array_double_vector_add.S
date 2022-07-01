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
	lla	t0, double_array_a
	lla	t1, double_array_b
	fadd.d	ft0, t0, t1
	fsd	ft0, -80(sp)
	ld	t0, -80(sp)
	mv	t1, zero
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	mv	t1, zero
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t0, -80(sp)
	addi	t1, zero, 1
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	addi	t1, zero, 1
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t0, -80(sp)
	addi	t1, zero, 2
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	addi	t1, zero, 2
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t0, -80(sp)
	addi	t1, zero, 3
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	addi	t1, zero, 3
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t0, -80(sp)
	addi	t1, zero, 4
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	addi	t1, zero, 4
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	ld	t0, -80(sp)
	addi	t1, zero, 5
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	addi	t0, sp, -56
	addi	t1, zero, 5
	ld	t2, -72(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	addi	t0, sp, -56
	addi	t1, zero, 5
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -64(sp)
	fld	fa0, -64(sp)
	addi	sp, sp, -80
	call	print_double
	addi	sp, sp, 80
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
