; ** por compatibilidad se omiten tildes **
; ==============================================================================
; TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
; ==============================================================================
; definicion de rutinas de atencion de interrupciones

%include "imprimir.mac"
extern screen_pintar
BITS 32

sched_tarea_offset:     dd 0x00
sched_tarea_selector:   dw 0x00
error_msg: db     'Excepcion!:'
error_len equ    $ - error_msg

;; PIC
extern fin_intr_pic1

;; Sched
extern sched_tick
extern sched_tarea_actual


;;
;; Definición de MACROS
;; -------------------------------------------------------------------------- ;;
	
%macro ISR 1
global _isr%1

_isr%1:
	push ebp
	mov ebp,esp
	push ebx
	push esi
	
    mov eax, %1
    mov ebx,10
	xor esi,esi
	div bl
	mov si,ax
	
	add ax,48
    mov ecx,40
    mov ebx,25
    xor edx,edx
    mov edx,0xaa
      
    push ecx
    push ebx
    push edx
    push eax
	
	imprimir_texto_mp error_msg,error_len,0xaa,25,33
	call screen_pintar
	
	shr si,8
	add si,48
    mov ecx,41
    mov ebx,25
    xor edx,edx
    mov edx,0xaa
      
    push ecx
    push ebx
    push edx
    push esi
	
	call screen_pintar

	
	add esp,8
	pop esi	
	pop ebx
	pop ebp
    jmp $

%endmacro

;global _isr0
;_isr0:
;		jmp $
		
;;
;; Datos
;; -------------------------------------------------------------------------- ;;
; Scheduler

;;
;; Rutina de atención de las EXCEPCIONES
;; -------------------------------------------------------------------------- ;;
ISR 0
ISR 1
ISR 2
ISR 3
ISR 4
ISR 5
ISR 6
ISR 7
ISR 8
ISR 9
ISR 10
ISR 11
ISR 12
ISR 13
ISR 14
ISR 15
ISR 16
ISR 17
ISR 18
ISR 19
ISR 20
ISR 21
ISR 22
ISR 23
ISR 24
ISR 25
ISR 26
ISR 27
ISR 28
ISR 29
ISR 30
ISR 31







;;
;; Rutina de atención del RELOJ
;; -------------------------------------------------------------------------- ;;

;;
;; Rutina de atención del TECLADO
;; -------------------------------------------------------------------------- ;;

;;
;; Rutinas de atención de las SYSCALLS
;; -------------------------------------------------------------------------- ;;


