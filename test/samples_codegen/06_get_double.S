iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	fmv.d.x	ft0, zero
	fsd	ft0, -16(sp)
	addi	sp, sp, -24
	call	get_double
	addi	sp, sp, 24
	fsd	fa0, -24(sp)
	fld	ft0, -24(sp)
	fsd	ft0, -16(sp)
	fld	fa0, -16(sp)
	addi	sp, sp, -24
	call	print_double
	addi	sp, sp, 24
	mv	a0, zero
	ld	ra, -8(sp)
	ret
