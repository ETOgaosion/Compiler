iobuff:
	.zero 80
	.equ	ImmValue_0, 0x40133333

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	li	t0, ImmValue_0
	fmv.w.x	ft0, t0
	fsw	ft0, -12(sp)
	flw	fa0, -12(sp)
	addi	sp, sp, -16
	call	print_float
	addi	sp, sp, 16
	mv	a0, zero
	ld	ra, -8(sp)
	ret
