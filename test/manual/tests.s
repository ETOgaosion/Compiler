.data
.globl	arr
.type	arr, %object
arr:
	.word	0x1
	.word	0x2
	.word	0x21
	.word	0x4
	.word	0x5
	.word	0x6

.data
.globl	N
.type	N, %object
N:
	.word	0xffffffff

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	ldr	v1, [sp, #-16]
	ldr	v3, =6
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-40]
	ldr	v1, [sp, #-40]
	cmp	v1, #0
	beq	L_0_main
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-36]
	ldr	v3, =7
	lsl	v2, v1, v3
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-32]
	ldr	v1, =arr
	ldr	v2, [sp, #-32]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-12]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
	b	L_1_main
L_0_main:
	ldr	a1, [sp, #-12]
	add	sp, sp, #-40
	bl	putint
	add	sp, sp, #40
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
