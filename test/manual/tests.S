.text
.align 1
.globl	main
.type	main, @function
main:
	addi	a0, zero, 100
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	lw	t1, -12(sp)
	addi	t0, t1, 1000
	sw	t0, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -16(sp)
	lw	t0, -24(sp)
	sw	t0, -16(sp)
	lw	a0, -16(sp)
	addi	sp, sp, -32
	call	print_int
	addi	sp, sp, 32
	mv	a0, zero
	ret
