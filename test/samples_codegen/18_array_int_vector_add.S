iobuff:
	.zero 80
.data
.globl	n
.type	n, @object
n:
	.word	0x6

.data
.globl	int_array_b
.type	int_array_b, @object
int_array_b:
	.word	0x7
	.word	0x8
	.word	0x9
	.word	0xa
	.word	0xb
	.word	0xc

.data
.globl	int_array_a
.type	int_array_a, @object
int_array_a:
	.word	0x1
	.word	0x2
	.word	0x3
	.word	0x4
	.word	0x5
	.word	0x6

ImmValue_2:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

.text
.align 1
.globl	main
.type	main, @function
main:
	sd	ra, -8(sp)
	addi	sp, sp, -8
	call	int_array_vector_add
	addi	sp, sp, 8
	mv	a0, zero
	ld	ra, -8(sp)
	ret
