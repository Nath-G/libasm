section .text
	global  ft_strcmp
 
	ft_strcmp:
		mov		rcx, 0						;
		mov		rdx, 0						;
		loop:	
			cmp 	byte [rdi + rcx], 0		;*s1
	    	je		last_char				;
			cmp 	byte [rsi + rcx], 0		;*s2
			je		sup						;
			mov		dl, byte [rdi + rcx]	; tmp = *s1
			cmp     dl, byte [rsi + rcx]	;compare *s1 avec *s2
        	jg		sup						;
			jl		inf						;
			inc		rcx						;
			jmp		loop					;

		last_char:
			cmp		byte [rsi + rcx], 0		;*s2 
			jz		equal					;
			jmp		inf						;

		sup:
			mov		rax, 1					;
			ret								;
	
		inf:
			mov		rax, -1					;
			ret								;

		equal:
			mov rax, 0						;
			ret								; 
