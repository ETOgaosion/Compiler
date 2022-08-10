.data
.globl	a
.type	a, %object
a:
	.word	0x0

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
	ldr	v1, =a
	str	v2, [v1]
	ldr	a1, =a
	ldr	a1, [a1]
	add	sp, sp, #-16
	bl	func
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
.globl	func
.type	func, %function
func:
	push	{lr}
	str	a1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-16]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
