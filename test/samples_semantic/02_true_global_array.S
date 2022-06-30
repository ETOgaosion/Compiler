iobuff:
	.zero 80
.data
.globl	b
.type	b, @object
b:
	.word	0x4

.data
.globl	a
.type	a, @object
a:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4
	.word	0x0
	.word	0x0

ImmValue_0:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	lla	a0, b
	ld	ra, -8(sp)
	ret
