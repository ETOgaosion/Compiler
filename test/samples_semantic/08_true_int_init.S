iobuff:
	.zero 80
.data
.globl	b
.type	b, @object
b:
	.word	0x7

.data
.globl	a
.type	a, @object
a:
	.word	0x0

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 7
	addi	t1, zero, 2
	divw	t2, t0, t1
	sw	t2, -12(sp)
	lw	t0, -12(sp)
	lla	t1, a
	sw	t0, 0(t1)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
