.section .rodata
msg:   
    .string "Enter string\n"
    .equ stdin, 0
    .equ stdout, 1

.text
.align 1
.globl	main
.type	main, @function
main:
	sw	ra, -8(sp)
    li a0, stdout
    lla a1, msg
    li a2, 1           # length of the message
    li a3, 0
    li a7, 64           # _NR_sys_write
    ecall               # system call
	ret