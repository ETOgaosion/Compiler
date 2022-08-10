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
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	add	sp, sp, #-64
	bl	getint
	add	sp, sp, #64
	str	a1, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_0_main
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-48]
	add	sp, sp, #-64
	bl	getint
	add	sp, sp, #64
	str	a1, [sp, #-52]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-52]
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v3, [v1]
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-60]
	str	v1, [sp, #-16]
	b	L_1_main
L_0_main:
L_3_main:
	ldr	v1, [sp, #-16]
	cmp	v1, #0
	beq	L_2_main
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-56]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-36]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-12]
	ldr	v3, [sp, #-40]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	b	L_3_main
L_2_main:
	ldr	a1, [sp, #-12]
	ldr	a2, =79
	sub	sp, sp, #64
	bl	__aeabi_idivmod
	add	sp, sp, #64
	mov	v1, a2
	str	v1, [sp, #-64]
	ldr	a1, [sp, #-64]
	add	sp, sp, #-64
	bl	putint
	add	sp, sp, #64
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
