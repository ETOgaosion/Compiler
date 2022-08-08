.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =10
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
