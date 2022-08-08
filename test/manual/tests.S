ImmValue_0:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v1, ImmValue_0
	str	v1, [sp, #-24]
	ldr	v2, =1
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-32]
	ldr	v2, =4
	str	v2, [sp, #-28]
	ldr	v2, =1
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-32]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-28]
	add	v1, sp, #-24
	ldr	v2, [sp, #-28]
	ldr	v4, =3
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
