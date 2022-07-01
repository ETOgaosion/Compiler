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
.globl	double_array_add
.type	double_array_add, @function
double_array_add:
	sd	ra, -8(sp)
	lla	t0, ImmValue_2
	addi	t1, sp, -60
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
	sw	t0, -12(sp)
L_1_double_array_add:
	lw	t0, -12(sp)
	lla	t2, n
	lw	t1, 0(t2)
	slt	t2, t0, t1
	sb	t2, -76(sp)
	lb	t0, -76(sp)
	beqz	t0, L_0_double_array_add
	lla	t0, double_array_a
	lw	t1, -12(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -84(sp)
	lla	t0, double_array_b
	lw	t1, -12(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -92(sp)
	fld	ft0, -84(sp)
	fld	ft0, -92(sp)
	fadd.d	ft0, ft0, ft0
	fsd	ft0, -100(sp)
	addi	t0, sp, -60
	lw	t1, -12(sp)
	ld	t2, -100(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	sd	t2, 0(t0)
	addi	t0, sp, -60
	lw	t1, -12(sp)
	slli	t1, t1, 3
	addw	t0, t0, t1
	ld	t0, 0(t0)
	sd	t0, -72(sp)
	fld	fa0, -72(sp)
	addi	sp, sp, -104
	call	print_double
	addi	sp, sp, 104
	lw	t1, -12(sp)
	addi	t0, t1, 1
	sw	t0, -64(sp)
	lw	t0, -64(sp)
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
