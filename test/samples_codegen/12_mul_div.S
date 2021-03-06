iobuff:
	.zero 80
	.equ	ImmValue_3, 0x4004000000000000

	.equ	ImmValue_2, 0x400b333333333333

	.equ	ImmValue_1, 0x3fcccccd

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
	mulw	t2, t0, t1
	sw	t2, -96(sp)
	lw	t0, -96(sp)
	sw	t0, -36(sp)
	addi	sp, sp, -136
	call	get_int
	addi	sp, sp, 136
	sw	a0, -92(sp)
	lw	t0, -92(sp)
	sw	t0, -32(sp)
	lw	t0, -32(sp)
	addi	t1, zero, 2
	divw	t2, t0, t1
	sw	t2, -84(sp)
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
	lw	t0, -100(sp)
	sw	t0, -56(sp)
	flw	ft0, -56(sp)
	li	t0, ImmValue_0
	fmv.w.x	ft1, t0
	fmul.s	ft2, ft0, ft1
	fsw	ft2, -88(sp)
	lw	t0, -88(sp)
	sw	t0, -52(sp)
	addi	sp, sp, -136
	call	get_float
	addi	sp, sp, 136
	fsw	fa0, -108(sp)
	lw	t0, -108(sp)
	sw	t0, -64(sp)
	flw	ft0, -64(sp)
	li	t0, ImmValue_1
	fmv.w.x	ft1, t0
	fdiv.s	ft2, ft0, ft1
	fsw	ft2, -120(sp)
	lw	t0, -120(sp)
	sw	t0, -60(sp)
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
	ld	t0, -128(sp)
	sd	t0, -72(sp)
	fld	ft0, -72(sp)
	li	t0, ImmValue_2
	fmv.d.x	ft1, t0
	fmul.d	ft2, ft0, ft1
	fsd	ft2, -116(sp)
	ld	t0, -116(sp)
	sd	t0, -48(sp)
	addi	sp, sp, -136
	call	get_double
	addi	sp, sp, 136
	fsd	fa0, -136(sp)
	ld	t0, -136(sp)
	sd	t0, -24(sp)
	fld	ft0, -24(sp)
	li	t0, ImmValue_3
	fmv.d.x	ft1, t0
	fdiv.d	ft2, ft0, ft1
	fsd	ft2, -80(sp)
	ld	t0, -80(sp)
	sd	t0, -16(sp)
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
