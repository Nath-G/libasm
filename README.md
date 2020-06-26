# libasm
projet 42 2019-2020
* ASM 64 Bits : attention au calling convention
* fichier.s (pas asm inline)
* compilation avec nasm
* syntax Intel pas AT&T
* ft_strlen, ft_strcpy, ft_strcmp, ft_write, ft_read, ft_strdup
* Vérifier les erreurs lors des syscal et renvoyer correctement.
* Lecture de la variable erno (erno.h) depuis un fichier .c
* utilisation de extern___error autorisé
* Doc:
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

* Pour LIBASM :
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