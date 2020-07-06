;section .bss         ;Variable segment
 ; extern  __errno_location ;
   
section .text          ;Code Segment
   global ft_write

   extern  __errno_location ;
   ft_write:                
      mov rax, 1		; set call to write
      syscall					; call kernel so rax (write)
      mov   r8, rax
      cmp r8, 0;
      jnge exit_error		; if doesn't work, jmp exit error
	   jmp exit				; jump exit

   exit_error:
      ;push rbp
      ;mov rbp, rsp
      neg r8;
      call __errno_location
      mov qword[rax], r8  ;à terme r8 le num d'errur en faisant un neg avant?
      mov rax, -1				; set return to -1
      ;mov rsp, rbp
     ; pop rbp
      ret						; return

   exit:
	   mov rax, rdx				; set previous value of rdx, in return value
      ret						; return 