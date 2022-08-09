ImmValue_0:
	.word	0x1
	.word	0x2
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
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-72]
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-40]
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
