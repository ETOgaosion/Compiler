iobuff:
	.zero 80
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	t0, zero
	sw	t0, -12(sp)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
