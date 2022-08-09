.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =10
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =2
	mul	v2, v1, v3
	str	v2, [sp, #-20]
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-16]
	ldr	a1, [sp, #-16]
	pop	{pc}
