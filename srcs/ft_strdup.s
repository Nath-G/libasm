section .text
	global  ft_strdup
	extern	ft_strlen
	extern ft_strcpy
	extern	malloc

	ft_strdup:
		call	ft_strlen	;count arg0 (*str) then rdi, result in rax
		inc		rax			; add 1 for the stop point /0
		push	rdi			;stock str in the stack
		mov		rdi, rax	; stock len as arg0 for malloc call
		call	malloc		; address in rax
		mov		rdi, rax	;copy address from rax to arg0 (rdi/dest) for ft_strcpy call
		pop		rsi			;restore str from stack to arg1 (rsi/src) for ft_strcpy call
		call	ft_strcpy	; l'adresse de retour est poussé dans la pile
		ret