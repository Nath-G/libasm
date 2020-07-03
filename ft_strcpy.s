	global  ft_strcpy
	section .text

	ft_strcpy :
		push	rdx;
		push	rcx;
		cmp		rsi, 0;
		jz		is_null;
		cmp		rdi, 0;
		jz		is_null;
		mov		rdx, 0;
		mov		rcx, 0;
		loop :
			mov		dl, [rsi + rcx]		;copy (src + counter)->temp
			mov		[rdi + rcx], dl		;copy tempsrc to (dst + counter)
			cmp		byte[rsi + rcx], 0	;compare (src + counter) with \0
			je		last_char			;
			inc		rcx					;increment counter
			jmp		loop				;
		
		last_char:
			mov		rax, rdi			;copy dst
			pop		rdx					;
			pop		rcx					;
			ret							; 
		
		is_null :
			mov		rax, rsi			;copy src
			ret							;