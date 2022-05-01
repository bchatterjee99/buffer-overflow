
section .text
	global _start

_start:
	mov rbx, 0xaabbccdd
	mov rax, 0x0068732f
	mul 2
	mov rax, 59		; execve
	syscall
	mov rdx, 0xaabbccdd
