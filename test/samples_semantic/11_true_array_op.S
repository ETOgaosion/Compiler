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
	lw	t0, -20(sp)
	lw	t1, -16(sp)
	addw	t2, t0, t1
	sw	t2, -28(sp)
	mv	t1, zero
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	mv	t1, zero
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 1
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 1
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 2
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 2
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 3
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 3
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 4
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 4
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 5
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 5
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 6
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 6
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 7
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 7
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 8
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 8
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 9
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -24(sp)
	addi	t1, zero, 9
	lw	t2, -24(sp)
	lla	t0, c
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	mv	a0, zero
	ld	ra, -8(sp)
	ret
