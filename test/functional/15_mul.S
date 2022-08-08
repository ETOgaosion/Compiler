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
	ldr	v2, =10
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-12]
	mul	v3, v1, v2
	str	v3, [sp, #-20]
	ldr	a1, [sp, #-20]
	pop	{pc}
