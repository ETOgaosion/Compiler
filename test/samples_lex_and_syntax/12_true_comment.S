iobuff:
	.zero 80
ImmValue_0:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	lla	t0, ImmValue_0
	lla	t1, 
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t0, zero, 3
	sw	t0, -12(sp)
	ld	a0, -12(sp)
	ld	ra, -8(sp)
	ret
