iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 3
	sw	t0, -12(sp)
	lw	a0, -12(sp)
	addi	sp, sp, -16
	call	print_int
	addi	sp, sp, 16
	mv	a0, zero
	ld	ra, -8(sp)
	ret
