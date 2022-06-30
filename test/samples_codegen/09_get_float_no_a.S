iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -16
	call	get_float
	addi	sp, sp, 16
	fsw	fa0, -12(sp)
	flw	fa0, -12(sp)
	fld	fa0, -12(sp)
	addi	sp, sp, -16
	call	print_float
	addi	sp, sp, 16
	mv	a0, zero
	ld	ra, -8(sp)
	ret
