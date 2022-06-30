iobuff:
	.zero 80
.data
.globl	foo
.type	foo, @object
foo:
	.word	0x0

.text
.align 1
.globl	foo
.type	foo, @function
foo:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	lw	t0, -12(sp)
	lw	t1, -12(sp)
	addw	t2, t0, t1
	sw	t2, -16(sp)
	ld	a0, -16(sp)
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
