iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -16
	call	get_double
	addi	sp, sp, 16
	fsd	fa0, -16(sp)
	fld	fa0, -16(sp)
	addi	sp, sp, -16
	call	print_double
	addi	sp, sp, 16
	mv	a0, zero
	ld	ra, -8(sp)
	ret
