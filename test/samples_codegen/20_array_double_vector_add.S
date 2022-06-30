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
.globl	double_array_vector_add
.type	double_array_vector_add, @function
double_array_vector_add:
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
	lla	t0, double_array_a
	fmv.d.x	ft0, t0
	lla	t0, double_array_b
	fmv.d.x	ft0, t0
	fadd.d	ft0, ft0, ft0
	fsd	ft0, -40(sp)
	mv	t1, zero
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	mv	t0, zero
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 1
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	addi	t0, zero, 1
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 2
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	addi	t0, zero, 2
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 3
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	addi	t0, zero, 3
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 4
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	addi	t0, zero, 4
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 5
	lla	t0, t_0
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -32(sp)
	addi	t0, zero, 5
	fld	ft0, -32(sp)
	lla	ft0, double_array_c
	slli	t0, t0, 3
	addw	ft0, ft0, t0
	sd	ft0, 0(ft0)
	addi	t1, zero, 5
	lla	t0, double_array_c
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	fsd	t0, -24(sp)
	fld	fa0, -24(sp)
	addi	sp, sp, -40
	call	print_double
	addi	sp, sp, 40
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
