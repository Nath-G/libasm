section .bss         ;Variable segment
   extern  __errno_location ;
   
section .text          ;Code Segment
   global ft_read
  
   ft_read:                
      mov rax, 0		; set call to read
      syscall					; call kernel so rax (read)
      mov   r8, rax
      cmp r8, 0;
      jnge exit_error		; if doesn't work, jmp exit error
	   jmp exit				; jump exit

   exit_error:
      ;push rbp
      ;mov rbp, rsp
      neg r8;
      call __errno_location
      mov [rax], r8  ;
      mov rax, -1				; set return to -1
      ;mov rsp, rbp
     ; pop rbp
      ret						; return

   exit:
	   mov rax, rdx			; set previous value of rdx, in return value
      ret						; return 