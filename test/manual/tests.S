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

	.equ	ImmValue_7, 0xc

	.equ	ImmValue_6, 0xa

	.equ	ImmValue_0, 0x2

	.equ	ImmValue_3, 0x1

	.equ	ImmValue_5, 0x6

	.equ	ImmValue_2, 0x0

	.equ	ImmValue_4, 0x5

.text
.align 1
.globl	get_float
.type	get_float, @function
get_float:
	sw	ra, -8(sp)
	ecall	ft0, zero, 6
	fsw	ft0, 0(sp)
	flw	fa0, 0(sp)
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	get_double
.type	get_double, @function
get_double:
	sw	ra, -8(sp)
	ecall	ft0, zero, 6
	fsw	ft0, 0(sp)
	flw	fa0, 0(sp)
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	get_int
.type	get_int, @function
get_int:
	sw	ra, -8(sp)
	ecall	t0, zero, 5
	sw	t0, 0(sp)
	lw	a0, 0(sp)
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	print_int
.type	print_int, @function
print_int:
	sw	ra, -8(sp)
	sw	a0, 0(sp)
	lw	t0, 0(sp)
	ecall	zero, t0, 0
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sw	ra, -8(sp)
	li	t0, ImmValue_4
	sw	t0, 0(sp)
	li	t0, ImmValue_2
	sw	t0, -12(sp)
L_1_main:
	lw	t0, 0(sp)
	li	t1, ImmValue_5
	slt	t2, t0, t1
	sw	t2, -72(sp)
	lw	t0, -12(sp)
	li	t1, ImmValue_2
	xor	t2, t0
	seqz	t3, t2
	sw	t3, -52(sp)
	lw	t0, -72(sp)
	lw	t1, -52(sp)
	or	t2, t0
	sw	t2, -48(sp)
	lw	t0, -48(sp)
	beqz	t0, L_0_main
	lw	t0, 0(sp)
	lw	t1, -12(sp)
	addw	t2, t0, t1
	sw	t2, -40(sp)
	lw	t0, -40(sp)
	li	t1, ImmValue_6
	slt	t2, t0, t1
	not	t2, t2
	sw	t2, -56(sp)
	lw	t0, 0(sp)
	lw	t1, -12(sp)
	mulw	t2, t0, t1
	sw	t2, -76(sp)
	lw	t0, -76(sp)
	li	t1, ImmValue_6
	remw	t2, t0, t1
	sw	t2, -64(sp)
	lw	t0, -64(sp)
	li	t1, ImmValue_2
	xor	t2, t0
	snez	t3, t2
	sw	t3, -68(sp)
	lw	t0, -56(sp)
	lw	t1, -68(sp)
	and	t2, t0
	sw	t2, -44(sp)
	lw	t0, -44(sp)
	beqz	t0, L_2_main
	lla	t0, L_0_main
	jr	t0
L_2_main:
	lw	t0, 0(sp)
	li	t1, ImmValue_0
	mulw	t2, t0, t1
	sw	t2, -80(sp)
	lw	t0, -80(sp)
	li	t1, ImmValue_6
	addw	t2, t0, t1
	sw	t2, -60(sp)
	lw	t0, -60(sp)
	li	t1, ImmValue_7
	addw	t2, t0, t1
	sw	t2, -36(sp)
	li	a0, ImmValue_4
	li	t0, 
	subw	sp, sp, t0
	call	
	sw	a0, -32(sp)
	lw	t0, -36(sp)
	lw	t1, -32(sp)
	addw	t2, t0, t1
	sw	t2, -28(sp)
	lw	t0, -28(sp)
	sw	t0, -24(sp)
	lw	t0, 0(sp)
	li	t1, ImmValue_3
	addw	t2, t0, t1
	sw	t2, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	lla	t0, L_1_main
	jr	t0
L_0_main:
	lw	a0, -12(sp)
	li	t0, 
	subw	sp, sp, t0
	call	
	lw	a0, -12(sp)
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	a
.type	a, @function
a:
	sw	ra, -8(sp)
	sw	a0, -12(sp)
	lw	t0, -12(sp)
	li	t1, ImmValue_3
	addw	t2, t0, t1
	sw	t2, -16(sp)
	lw	a0, -16(sp)
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	print_float
.type	print_float, @function
print_float:
	sw	ra, -8(sp)
	fsw	fa0, 0(sp)
	flw	ft0, 0(sp)
	ecall	zero, ft0, 1
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	print_double
.type	print_double, @function
print_double:
	sw	ra, -8(sp)
	fsw	fa0, 0(sp)
	flw	ft0, 0(sp)
	ecall	zero, ft0, 1
	lw	ra, -8(sp)
	ret
.text
.align 1
.globl	print_bool
.type	print_bool, @function
print_bool:
	sw	ra, -8(sp)
	sw	a0, 0(sp)
	lw	t0, 0(sp)
	ecall	zero, t0, 0
	lw	ra, -8(sp)
	ret
