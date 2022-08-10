ImmValue_0:
	.word	0x1
	.word	0x2
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
.type	main, %function
main:
	push	{lr}
	ldr	v2, =2
	str	v2, [sp, #-24]
	ldr	v2, =20
	str	v2, [sp, #-20]
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	ldr	v1, [sp, #-24]
	ldr	v2, [sp, #-20]
	cmp	v1, v2
	ldrlt	v3, =1
	ldrge	v3, =0
	str	v3, [sp, #-36]
	ldr	v1, [sp, #-36]
	cmp	v1, #0
	beq	L_0_main
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-52]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-56]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-64]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-68]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-68]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-72]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-56]
	ldr	v3, [sp, #-72]
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v3, [v1]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-76]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-80]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-80]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-12]
	ldr	v3, [sp, #-40]
	add	v1, v2, v3
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-60]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-48]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-48]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-32]
	ldr	a1, [sp, #-32]
	add	sp, sp, #-80
	bl	putint
	add	sp, sp, #80
	eor	v1, v1, v1
	add	a1, v1, #10
	add	sp, sp, #-80
	bl	putch
	add	sp, sp, #80
	ldr	v2, [sp, #-24]
	add	v1, v2, #1
	str	v1, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-24]
	b	L_1_main
L_0_main:
	ldr	a1, [sp, #-12]
	pop	{pc}
