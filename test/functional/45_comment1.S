.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
