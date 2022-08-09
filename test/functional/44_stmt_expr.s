.data
.globl	n
.type	n, %object
n:
	.word	0xa

.data
.globl	k
.type	k, %object
k:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =1
	ldr	v1, =k
	str	v2, [v1]
L_1_main:
	ldr	v2, =n
	ldr	v1, [v2]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-32]
	cmp	v1, v2
	ldrle	v3, =1
	ldrgt	v3, =0
	str	v3, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, [sp, #-12]
	add	v1, v2, #1
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	v3, =k
	ldr	v2, [v3]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v3, =k
	ldr	v2, [v3]
	ldr	v4, =k
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-16]
	ldr	v1, [sp, #-16]
	ldr	v2, =k
	str	v1, [v2]
	b	L_1_main
L_0_main:
	ldr	a1, =k
	add	sp, sp, #-32
	bl	putint
	add	sp, sp, #32
	ldr	a1, =k
	pop	{pc}
