	global  ft_strcmp
	section .text
 
	ft_strcmp:
		push	rdx							;
		push	rcx							;		
		cmp		rdi, 0						;*s1
		jz		is_null						;
		cmp		rsi, 0						;*s2
		jz		is_null						;
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

		is_null:
			pop		rdx						;
			pop		rcx						;
			ret;

		last_char:
			cmp		byte [rsi + rcx], 0		;*s2 
			jz		equal					;
			jmp		inf						;

		sup:
			mov		rax, 1					;
			pop		rdx						;
			pop		rcx						;
			ret								;
	
		inf:
			mov		rax, -1					;
			pop		rdx						;
			pop		rcx						;
			ret								;

		equal:
			mov rax, 0						;
			pop		rdx						;
			pop		rcx						;
			ret								; 
