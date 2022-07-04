iobuff:
	.zero 80
.data
.globl	a
.type	a, @object
a:
	.word	0x2

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
