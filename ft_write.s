section .text          ;Code Segment
   global ft_write

;section .data   
;   extern errno


ft_write:                
	;push r8;
  ; push r9;
   mov rcx, rsi;     save msg in rcx
   ;cmp rcx, 0;       null pointer
   ;je exit_error;
   mov rax, 1		; set call to write
   syscall					; call kernel so rax (write)
   mov r15, rax;
   cmp rax, 0;
   jnge exit_error		; if doesn't work, write set flags carry to 1 so jmp exit error
	jmp exit				; jump exit

exit_error:
	
  ; mov   [rax], r15;
   ;call erno;
   mov rax, -1				; set return to -1
   ;pop r8;
  ; pop r9;
	;mov rcx, rbx;
   ret						; return

exit:
	mov rax, rdx				; set previous value of rdx save in r8, in return value
;	pop r8;
  ; pop r9;
   ret						; return 
	