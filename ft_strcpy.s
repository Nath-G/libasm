	global  ft_strcpy
	section .text


	ft_strcpy:

		cmp		rsi, 0;
		jz		segfault;
		start :
			mov		rsi, rdi				;
			cmp		byte [rax + rdi], 0		;
			je		end						;
			inc		rax						;
			jmp	start						;

		end :
			mov rax, rsi;
			ret; 
		segfault :
			ret;	
