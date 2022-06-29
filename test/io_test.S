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
    ld  t0, a
	ret