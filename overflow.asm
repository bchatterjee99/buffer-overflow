	.global _start
	.text
_start:
	movq $0xaabbccdd, %rbx

	# get string "/bin/sh" in stack
	movq $0x0068732f, %rax   	# half string
	movq $1073741824, %rbx 		# 2^30
	mulq %rbx
	movq $4, %rbx			# 2^2
	mulq %rbx
	orq $0x6e69622f, %rax
	pushq %rax

	# print check
	movq %rsp, %rsi
	movq $1, %rax
	movq $1, %rdi
	movq $8, %rdx
	syscall




	movq $0, %rdi			# file-name (/bin/sh)
	movq $60, %rax  		# sys_execve
	syscall
	movq $0xaabbccdd, %rbx


