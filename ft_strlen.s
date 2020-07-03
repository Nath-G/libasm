global  ft_strlen
	section .text

	ft_strlen:
        mov			rax, 0				;
		start :
			cmp		byte [rax + rdi], 0	;
			je		end					;
			inc		rax					;
			jmp	start					;

		end :
			ret							; 
