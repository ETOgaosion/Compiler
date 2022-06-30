iobuff:
	.zero 80
	.equ	ImmValue_2, 0x400b333333333333

	.equ	ImmValue_3, 0x4000cccccccccccd

	.equ	ImmValue_1, 0x40133333

	.equ	ImmValue_0, 0x404ccccd

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	t0, zero
	sw	t0, -40(sp)
	mv	t0, zero
	sw	t0, -36(sp)
	mv	t0, zero
	sw	t0, -32(sp)
	mv	t0, zero
	sw	t0, -28(sp)
	addi	sp, sp, -136
	call	get_int
	addi	sp, sp, 136
	sw	a0, -104(sp)
	lw	t0, -104(sp)
	sw	t0, -40(sp)
	lw	t0, -40(sp)
	addi	t1, zero, 3
	subw	t2, t0, t1
	sw	t2, -96(sp)
	lw	t0, -96(sp)
	sw	t0, -36(sp)
	addi	sp, sp, -136
	call	get_int
	addi	sp, sp, 136
	sw	a0, -92(sp)
	lw	t0, -92(sp)
	sw	t0, -32(sp)
	lw	t1, -32(sp)
	addi	t0, t1, 2
	sw	t0, -84(sp)
	lw	t0, -84(sp)
	sw	t0, -28(sp)
	lw	a0, -36(sp)
	addi	sp, sp, -136
	call	print_int
	addi	sp, sp, 136
	lw	a0, -28(sp)
	addi	sp, sp, -136
	call	print_int
	addi	sp, sp, 136
	fmv.w.x	ft0, zero
	fsw	ft0, -56(sp)
	fmv.w.x	ft0, zero
	fsw	ft0, -52(sp)
	fmv.w.x	ft0, zero
	fsw	ft0, -64(sp)
	fmv.w.x	ft0, zero
	fsw	ft0, -60(sp)
	addi	sp, sp, -136
	call	get_float
	addi	sp, sp, 136
	fsw	fa0, -100(sp)
	flw	ft0, -100(sp)
	fsw	ft0, -56(sp)
	flw	ft0, -56(sp)
	li	t0, ImmValue_0
	fmv.w.x	ft0, t0
	fsub.s	ft0, ft0, ft0
	fsw	ft0, -88(sp)
	flw	ft0, -88(sp)
	fsw	ft0, -52(sp)
	addi	sp, sp, -136
	call	get_float
	addi	sp, sp, 136
	fsw	fa0, -108(sp)
	flw	ft0, -108(sp)
	fsw	ft0, -64(sp)
	flw	ft0, -64(sp)
	li	t0, ImmValue_1
	fmv.w.x	ft0, t0
	fadd.s	ft0, ft0, ft0
	fsw	ft0, -120(sp)
	flw	ft0, -120(sp)
	fsw	ft0, -60(sp)
	flw	fa0, -52(sp)
	addi	sp, sp, -136
	call	print_float
	addi	sp, sp, 136
	flw	fa0, -60(sp)
	addi	sp, sp, -136
	call	print_float
	addi	sp, sp, 136
	fmv.d.x	ft0, zero
	fsd	ft0, -72(sp)
	fmv.d.x	ft0, zero
	fsd	ft0, -48(sp)
	fmv.d.x	ft0, zero
	fsd	ft0, -24(sp)
	fmv.d.x	ft0, zero
	fsd	ft0, -16(sp)
	addi	sp, sp, -136
	call	get_double
	addi	sp, sp, 136
	fsd	fa0, -128(sp)
	fld	ft0, -128(sp)
	fsd	ft0, -72(sp)
	fld	ft0, -72(sp)
	li	t0, ImmValue_2
	fmv.d.x	ft0, t0
	fadd.d	ft0, ft0, ft0
	fsd	ft0, -116(sp)
	fld	ft0, -116(sp)
	fsd	ft0, -48(sp)
	addi	sp, sp, -136
	call	get_double
	addi	sp, sp, 136
	fsd	fa0, -136(sp)
	fld	ft0, -136(sp)
	fsd	ft0, -24(sp)
	fld	ft0, -24(sp)
	li	t0, ImmValue_3
	fmv.d.x	ft0, t0
	fadd.d	ft0, ft0, ft0
	fsd	ft0, -80(sp)
	fld	ft0, -80(sp)
	fsd	ft0, -16(sp)
	fld	fa0, -48(sp)
	addi	sp, sp, -136
	call	print_double
	addi	sp, sp, 136
	fld	fa0, -16(sp)
	addi	sp, sp, -136
	call	print_double
	addi	sp, sp, 136
	mv	a0, zero
	ld	ra, -8(sp)
	ret
