.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	defn
	add	sp, sp, #16
	str	a1, [sp, #-16]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	defn
.type	defn, %function
defn:
	push	{lr}
	eor	v1, v1, v1
	add	a1, v1, #4
	pop	{pc}
