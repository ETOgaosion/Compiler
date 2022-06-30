iobuff:
	.zero 80
.data
.globl	a
.type	a, @object
a:
	.word	
	.word	
	.word	
	.word	

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	mv	t0, zero
	sw	t0, -12(sp)
	lw	t0, -12(sp)
	addi	t1, zero, 1
	addw	t2, t0, t1
	sw	t2, -20(sp)
	lw	t0, -20(sp)
	sw	t0, -16(sp)
	ld	a0, -12(sp)
	ld	ra, -8(sp)
	ret
