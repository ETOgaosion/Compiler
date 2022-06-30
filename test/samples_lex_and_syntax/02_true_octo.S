iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 0
	sw	t0, -12(sp)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
