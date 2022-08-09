ImmValue_0:
	.word	0x0
	.word	0x4
	.word	0x3
	.word	0x4
	.word	0x5
	.word	0x6
	.word	0x7
	.word	0x8

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-40]
	ldr	v2, =1
	str	v2, [sp, #-52]
	ldr	v2, =1
	str	v2, [sp, #-48]
	ldr	v2, =3
	ldr	v3, =2
	mul	v1, v2, v3
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-52]
	ldr	v3, [sp, #-48]
	add	v1, v2, v3
	str	v1, [sp, #-48]
	ldr	v1, [sp, #-40]
	ldr	v2, [sp, #-48]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-44]
	ldr	a1, [sp, #-44]
	add	sp, sp, #-56
	bl	putint
	add	sp, sp, #56
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
