iobuff:
	.zero 80
ImmValue_4:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

ImmValue_1:
	.word	0x1
	.word	0x2
	.word	0x0
	.word	0x0

ImmValue_2:
	.word	0x3
	.word	0x4

ImmValue_0:
	.word	0x1
	.word	0x2

ImmValue_3:
	.word	0x3
	.word	0x4
	.word	0x0
	.word	0x0

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	t0, zero, 3
	sw	t0, -20(sp)
	lla	t0, ImmValue_1
	lla	t1, 
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	lla	t0, ImmValue_3
	lla	t1, 
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	lla	t0, ImmValue_4
	lla	t1, 
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	addi	t1, t1, 4
	sw	t0, 0(t1)
	lw	t0, -28(sp)
	lw	t1, -32(sp)
	addw	t2, t0, t1
	sw	t2, -52(sp)
	mv	t1, zero
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -48(sp)
	mv	t1, zero
	lw	t2, -48(sp)
	lla	t0, d
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 1
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -48(sp)
	addi	t1, zero, 1
	lw	t2, -48(sp)
	lla	t0, d
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 2
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -48(sp)
	addi	t1, zero, 2
	lw	t2, -48(sp)
	lla	t0, d
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	addi	t1, zero, 3
	lla	t0, t_0
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -48(sp)
	addi	t1, zero, 3
	lw	t2, -48(sp)
	lla	t0, d
	slli	t1, t1, 2
	addw	t0, t0, t1
	sw	t2, 0(t0)
	lla	t0, ImmValue_4
	lla	t1, 
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	lla	t0, ImmValue_4
	lla	t1, 
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	lla	t0, ImmValue_4
	lla	t1, 
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	addi	t1, t1, 4
	sb	t0, 0(t1)
	mv	t1, zero
	lla	t0, f
	slli	t1, t1, 2
	addw	t0, t0, t1
	lb	t0, 0(t0)
	sb	t0, -44(sp)
	mv	t1, zero
	lb	t2, -44(sp)
	lla	t0, g
	slli	t1, t1, 2
	addw	t0, t0, t1
	sb	t2, 0(t0)
	addi	t1, zero, 1
	lla	t0, f
	slli	t1, t1, 2
	addw	t0, t0, t1
	lb	t0, 0(t0)
	sb	t0, -44(sp)
	addi	t1, zero, 1
	lb	t2, -44(sp)
	lla	t0, g
	slli	t1, t1, 2
	addw	t0, t0, t1
	sb	t2, 0(t0)
	addi	t1, zero, 2
	lla	t0, f
	slli	t1, t1, 2
	addw	t0, t0, t1
	lb	t0, 0(t0)
	sb	t0, -44(sp)
	addi	t1, zero, 2
	lb	t2, -44(sp)
	lla	t0, g
	slli	t1, t1, 2
	addw	t0, t0, t1
	sb	t2, 0(t0)
	addi	t1, zero, 3
	lla	t0, f
	slli	t1, t1, 2
	addw	t0, t0, t1
	lb	t0, 0(t0)
	sb	t0, -44(sp)
	addi	t1, zero, 3
	lb	t2, -44(sp)
	lla	t0, g
	slli	t1, t1, 2
	addw	t0, t0, t1
	sb	t2, 0(t0)
	mv	t1, zero
	lla	t0, d
	slli	t1, t1, 2
	addw	t0, t0, t1
	lw	t0, 0(t0)
	sw	t0, -40(sp)
	ld	a0, -40(sp)
	ld	ra, -8(sp)
	ret
