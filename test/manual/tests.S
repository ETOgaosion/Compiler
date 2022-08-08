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
	ldr	v2, [sp, #-40]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-36]
	ldr	v1, ImmValue_0
	ldr	v2, [sp, #-28]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-48]
	ldr	a1, [sp, #-36]
	ldr	a1, [sp, #-48]
	add	sp, sp, #-56
	bl	a
	add	sp, sp, #56
	str	a1, [sp, #-44]
	ldr	a1, [sp, #-44]
	pop	{pc}
.text
.align 1
.globl	a
.type	a, %function
a:
	push	{lr}
	str	a1, [sp, #-16]
	str	a2, [sp, #-12]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-12]
	mul	v3, v1, v2
	str	v3, [sp, #-20]
	ldr	a1, [sp, #-20]
	pop	{pc}
