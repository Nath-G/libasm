section .bss         ;Variable segment
   extern  __errno_location ;
   
section .text
   global ft_write
   
ft_write:                
      mov rax, 1
      syscall
      cmp rax, 0
      jnge exit_error
	   ret

   exit_error:
      mov   r8, rax
      neg   r8;
      call __errno_location
      mov [rax], r8
      mov rax, -1
      ret