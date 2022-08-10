ImmValue_3:
	.word	0x0
	.word	0x6
	.word	0x3
	.word	0x4
	.word	0x5
	.word	0x6
	.word	0x7
	.word	0x8

ImmValue_2:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x0
	.word	0x5
	.word	0x0
	.word	0x7
	.word	0x8

ImmValue_1:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4
	.word	0x5
	.word	0x6
	.word	0x7
	.word	0x8

ImmValue_0:
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
	str	v1, [sp, #-28]
	ldr	v1, =ImmValue_1
	str	v1, [sp, #-24]
	ldr	v1, =ImmValue_1
	str	v1, [sp, #-20]
	ldr	v1, =ImmValue_2
	str	v1, [sp, #-16]
	ldr	v1, =ImmValue_3
	str	v1, [sp, #-12]
	ldr	v2, =1
	str	v2, [sp, #-48]
	ldr	v2, =1
	str	v2, [sp, #-60]
	ldr	v2, =3
	ldr	v3, =2
	mul	v1, v2, v3
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-60]
	add	v1, v2, v3
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-60]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-80]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-84]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-88]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v3, =2
	mul	v1, v2, v3
	str	v1, [sp, #-84]
	ldr	v2, [sp, #-84]
	ldr	v3, [sp, #-88]
	add	v1, v2, v3
	str	v1, [sp, #-88]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-88]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-68]
	ldr	v2, [sp, #-80]
	ldr	v3, [sp, #-68]
	add	v1, v2, v3
	str	v1, [sp, #-76]
	ldr	v2, =1
	str	v2, [sp, #-52]
	ldr	v2, =1
	str	v2, [sp, #-56]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v3, =2
	mul	v1, v2, v3
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-52]
	ldr	v3, [sp, #-56]
	add	v1, v2, v3
	str	v1, [sp, #-56]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-56]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-44]
	ldr	v2, [sp, #-76]
	ldr	v3, [sp, #-44]
	add	v1, v2, v3
	str	v1, [sp, #-72]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-40]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-36]
	ldr	v2, =2
	ldr	v3, =2
	mul	v1, v2, v3
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-40]
	ldr	v3, [sp, #-36]
	add	v1, v2, v3
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-28]
	ldr	v2, [sp, #-36]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-72]
	ldr	v3, [sp, #-32]
	add	v1, v2, v3
	str	v1, [sp, #-64]
	ldr	a1, [sp, #-64]
	add	sp, sp, #-88
	bl	putint
	add	sp, sp, #88
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
