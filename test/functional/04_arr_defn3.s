ImmValue_3:
	.word	0x0
	.word	0x4
	.word	0x0
	.word	0x0
	.word	0x3
	.word	0x4
	.word	0x0
	.word	0x0
	.word	0x5
	.word	0x6
	.word	0x0
	.word	0x0
	.word	0x7
	.word	0x8

ImmValue_2:
	.word	0x1
	.word	0x2
	.word	0x0
	.word	0x0
	.word	0x3
	.word	0x0
	.word	0x5
	.word	0x7
	.word	0x8

ImmValue_1:
	.word	0x1
	.word	0x2
	.word	0x0
	.word	0x0
	.word	0x3
	.word	0x4
	.word	0x0
	.word	0x0
	.word	0x5
	.word	0x6
	.word	0x0
	.word	0x0
	.word	0x7
	.word	0x8

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
	str	v2, [sp, #-168]
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-136]
	ldr	v1, =ImmValue_1
	str	v1, [sp, #-104]
	ldr	v1, =ImmValue_2
	str	v1, [sp, #-72]
	ldr	v2, =1
	str	v2, [sp, #-244]
	ldr	v1, [sp, #-244]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-244]
	ldr	v2, =4
	str	v2, [sp, #-212]
	ldr	v2, =2
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-244]
	ldr	v2, [sp, #-244]
	ldr	v3, [sp, #-212]
	add	v1, v2, v3
	str	v1, [sp, #-212]
	add	v1, sp, #-72
	ldr	v2, [sp, #-212]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-196]
	ldr	v2, =1
	str	v2, [sp, #-192]
	ldr	v1, [sp, #-192]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-192]
	ldr	v2, =4
	str	v2, [sp, #-208]
	ldr	v2, =2
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-192]
	ldr	v2, [sp, #-192]
	ldr	v3, [sp, #-208]
	add	v1, v2, v3
	str	v1, [sp, #-208]
	add	v1, sp, #-104
	ldr	v2, [sp, #-208]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-224]
	ldr	v1, =ImmValue_3
	str	v1, [sp, #-40]
	ldr	v2, =1
	str	v2, [sp, #-220]
	ldr	v1, [sp, #-220]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-220]
	ldr	v2, =4
	str	v2, [sp, #-228]
	ldr	v2, =3
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-220]
	ldr	v2, [sp, #-220]
	ldr	v3, [sp, #-228]
	add	v1, v2, v3
	str	v1, [sp, #-228]
	add	v1, sp, #-40
	ldr	v2, [sp, #-228]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-232]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-236]
	ldr	v1, [sp, #-236]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-236]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-188]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-236]
	ldr	v2, [sp, #-236]
	ldr	v3, [sp, #-188]
	add	v1, v2, v3
	str	v1, [sp, #-188]
	add	v1, sp, #-40
	ldr	v2, [sp, #-188]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-200]
	ldr	v2, [sp, #-232]
	ldr	v3, [sp, #-200]
	add	v1, v2, v3
	str	v1, [sp, #-240]
	ldr	v2, =1
	str	v2, [sp, #-248]
	ldr	v1, [sp, #-248]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-248]
	ldr	v2, =4
	str	v2, [sp, #-252]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-248]
	ldr	v2, [sp, #-248]
	ldr	v3, [sp, #-252]
	add	v1, v2, v3
	str	v1, [sp, #-252]
	add	v1, sp, #-40
	ldr	v2, [sp, #-252]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-204]
	ldr	v2, [sp, #-240]
	ldr	v3, [sp, #-204]
	add	v1, v2, v3
	str	v1, [sp, #-184]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-180]
	ldr	v1, [sp, #-180]
	ldr	v3, =2
	lsl	v2, v1, v3
	str	v2, [sp, #-180]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-176]
	ldr	v2, =2
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-180]
	ldr	v2, [sp, #-180]
	ldr	v3, [sp, #-176]
	add	v1, v2, v3
	str	v1, [sp, #-176]
	add	v1, sp, #-168
	ldr	v2, [sp, #-176]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-216]
	ldr	v2, [sp, #-184]
	ldr	v3, [sp, #-216]
	add	v1, v2, v3
	str	v1, [sp, #-172]
	ldr	a1, [sp, #-172]
	add	sp, sp, #-256
	bl	putint
	add	sp, sp, #256
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
