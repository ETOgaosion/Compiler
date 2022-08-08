.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	ldr	a2, =3
	sub	sp, sp, #16
	bl	__aeabi_idiv
	add	sp, sp, #16
	mov	v1, a1
	ldr	a1, [sp, #-16]
	pop	{pc}
