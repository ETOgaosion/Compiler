iobuff:
	.zero 80
.text
.align 1
.globl	func
.type	func, @function
func:
	sd	ra, -8(sp)
	sw	a0, -12(sp)
	addi	t0, zero, 2
	sw	t0, -12(sp)
	addi	t0, zero, 3
	sw	t0, -16(sp)
	lw	t0, -12(sp)
	lw	t1, -16(sp)
	addw	t2, t0, t1
	sw	t2, -24(sp)
	lw	t0, -24(sp)
	sw	t0, -20(sp)
	ld	ra, -8(sp)
	ret
.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 4
	sw	t0, -16(sp)
	addi	t0, zero, 2
	sw	t0, -12(sp)
	ld	a0, -12(sp)
	addi	t0, zero, 24
	subw	sp, sp, t0
	call	func
	ld	a0, -16(sp)
	ld	ra, -8(sp)
	ret
