# libasm
projet 42 2019-2020
* ASM 64 Bits : attention au calling convention
* fichier.s (pas asm inline)
* compilation avec nasm
* syntax Intel pas AT&T
* ft_strlen (man 3), ft_strcpy (man 3), ft_strcmp (man 3), ft_write (man 2), ft_read  (man 2), ft_strdup (man 3 strdup, malloc autorisé)
* Vérifier les erreurs lors des syscal et renvoyer correctement.
* Lecture de la variable erno (erno.h) depuis un fichier .c
* utilisation de extern___error autorisé

# Doc/srcs:
 * https://www.youtube.com/watch?reload=9&v=ZBOfeiRN3T8
 * https://cs.lmu.edu/~ray/notes/nasmtutorial/
 * https://software.intel.com/content/www/us/en/develop/articles/intel-sdm.html
 * https://stackoverflow.com/questions/15304829/how-to-return-errno-in-assembly
Stack Overflow
 * http://www.keil.com/support/man/docs/armasm/armasm_dom1361290016692.htm
keil.com
 * https://stackoverflow.com/questions/14574696/what-values-can-the-carry-flag-hold-and-how-to-check-its-status-in-x86-assembly
 * https://jameshfisher.com/2016/12/13/c-errno/
 * https://www.lacl.fr/tan/asm
 * https://perso.univ-st-etienne.fr/ezequel/L2info/coursAssembleur_x86_64.pdf
 * https://www.tutorialspoint.com/assembly_programming/assembly_system_calls.htm

# Registers
; 64-bit [QWORD]
R0  R1  R2  R3  R4  R5  R6  R7  R8  R9  R10  R11  R12  R13  R14  R15
RAX RCX RDX RBX RSP RBP RSI RDI

; 32-bit [DWORD]
R0D R1D R2D R3D R4D R5D R6D R7D R8D R9D R10D R11D R12D R13D R14D R15D
EAX ECX EDX EBX ESP EBP ESI EDI

; 16-bit [WORD]
R0W R1W R2W R3W R4W R5W R6W R7W R8W R9W R10W R11W R12W R13W R14W R15W
AX  CX  DX  BX  SP  BP  SI  DI

; 8-bit [BYTE]
R0B R1B R2B R3B R4B R5B R6B R7B R8B R9B R10B R11B R12B R13B R14B R15B
AL  CL  DL  BL  SPL BPL SIL DIL

; 128-bit (used for floating point operations mostly)
XMM0 ... XMM15

# Common instructions

; Save register
push	REG
pop		REG

; Set register value
mov		REG, VALUE	; DEST = VALUE

; Common operations
add		DEST, VALUE	; DEST = DEST + VALUE
sub		-			; DEST = DEST - VALUE
inc		REG			; REG++
dec		-			; REG--
and		DEST, REG	; DEST = DEST & REG
xor		-			; DEST = DEST ^ REG
xor		REG, REG	; = mov	REG, 0
mul		REG			; REG = REG * RAX
div		REG			; REG = REG / RAX

; Dereferenced value
		[REG]		; = *REG

; Compare
cmp	REG, VALUE		; Set flags used by jmp variants

; Label
label:
		jmp	label	; next jumps depends on compare flags from cmp
		je	-		; is equal (jump if Z=1 after comp or sub)
		jne	-		; is not equal
		jl	-		; < VALUE
		jle	-		; <= VALUE
		jz	-		; = 0
		jnz	-		; != 0
		jg	-		; > VALUE
		jge	-		; >= VALUE

        JA/JNBE (above): saut si supérieur (non signé) 
        JNC/JAE/JNB : saut si C=0 (si supérieur ou égal en non signé) 
        JC/JB/JNAE (below): saut si C=1 (inférieur en non signé) 
        JE/JZ : saut si Z=1 (si égalité après CMP ou soustraction) 
        JNE/JNZ : saut si Z=0 (différent) 
        JP/JPE : saut si P=1 (parité paire (even)) 
        JNP/JPO : saut si P=0 (odd=impaire) 
        JO : saut si O=1 (dépassement de capacité en nombres signés) 
        JNO : saut si O=0 
        JS : saut si S=1 (nombre signé négatif) 
        JNS : saut si S=0 
        JG/JNLE (greater): saut si supérieur (nombres signés) 
        JGE/JNL : saut si supérieur ou égal (nombres signés) 
        JL/JNGE (less): saut si inférieur (nombres signés) 
        JLE/JNG : saut si inférieur ou égal (nombres signés) 
        JCXZ : saut si CX=0 (par exemple pour tester comment un LOOPZ REPZ s'est fini).

# Functions

; Function call
call	FUNCTION

; Parameters registers
RDI(s1 or dst) RSI(s2 or src) RDX RCX(counter) R8 R9

; Register to preserve
RBP RBX R12 R13 R14 R15	; You **MUST** push/pop them if you use them

; Return register
RAX

; syscall
mov		rax, CODE	; Then RDI, RSI etc.. for params
					; for the syscall number, see table in link below:
* https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

# Tests
 * For the direct testing on VM: do not forget to update the tester makefile from gcc to clang and remove the condition in the tester main.c
 * https://github.com/HappyTramp/libasm_test
