.data
.globl	a
.type	a, %object
a:
	.word	0x0
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
	ldr	v2, =4
	str	v2, [sp, #-20]
	ldr	v1, [sp, #-20]
	ldr	v3, =5
	lsl	v2, v1, v3
	str	v2, [sp, #-20]
	ldr	v2, =16
	str	v2, [sp, #-16]
	ldr	v1, =a
	ldr	v2, [sp, #-16]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
