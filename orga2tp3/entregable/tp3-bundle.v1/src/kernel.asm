; ** por compatibilidad se omiten tildes **
; ==============================================================================
; TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
; ==============================================================================

%include "imprimir.mac"
extern GDT_DESC
extern screen_pintar_fondo
extern screen_pintar_linea_v
extern screen_pintar_linea_h
extern screen_pintar_barraInferior
extern IDT_DESC
extern idt_inicializar
extern page_directory
extern inicializard
extern inicializart
global start


;; Saltear seccion de datos
jmp start

;;
;; Seccion de datos.
;; -------------------------------------------------------------------------- ;;
iniciando_mr_msg db     'Iniciando kernel (Modo Real)...'
iniciando_mr_len equ    $ - iniciando_mr_msg

iniciando_mp_msg db     'Iniciando kernel (Modo Protegido)...'
iniciando_mp_len equ    $ - iniciando_mp_msg

;;
;; Seccion de cÃ³digo.
;; -------------------------------------------------------------------------- ;;

;; Punto de entrada del kernel.
BITS 16
start:
    ; Deshabilitar interrupciones
    cli

    ; Cambiar modo de video a 80 X 50
    mov ax, 0003h
    int 10h ; set mode 03h
    xor bx, bx
    mov ax, 1112h
    int 10h ; load 8x8 font

    ; Imprimir mensaje de bienvenida
    imprimir_texto_mr iniciando_mr_msg, iniciando_mr_len, 0x07, 0, 0

		
    ; Habilitar A20  FAST A20
    call habilitar_A20
    ;~ in al, 0x92
	;~ test al, 2
	;~ jnz gdtload
	;~ or al, 2
	;~ and al, 0xFE
	;~ out 0x92, al
	
 
 gdtload:
	;~ call checkear_A20
	;Cargar la GDT	
	lgdt [GDT_DESC] 		
    
    ;Setear el bit PE del registro CR0
    
    mov eax,cr0 			
    or eax, 1
    mov cr0,eax
	
	;Saltar a modo protegido	
	jmp 0x50:modoProtegido	

BITS 32

modoProtegido:

    ;Establecer selectores de segmentos
	xor eax,eax							;eax  = 0
	mov ax,1000000b			
	mov ds,ax 							;DS = Data Segment lvl 0
	mov ax,1001011b
	mov gs,ax							;GS = Data Segment lvl 3
	mov ax,1011011b
	mov es,ax							;ES = Code Segment lvl 3
	
	;Establecer la base de la pila
	mov ax,1000000b
	mov ss,ax							;SS = Stack Segment lvl 0 (debe ser de esta prioridad?)		
	mov esp,0x27000
	mov ebp,0x27000
	;Establecer segmento de video
		
	mov ax,1100000b
	mov fs,ax							;FS = Video Segment lvl 0 (debe ser de esta prioridad?)
	
	; Imprimir mensaje de bienvenida
	imprimir_texto_mp iniciando_mp_msg,iniciando_mp_len,0xaa,0,0
	call screen_pintar_fondo 			;Inicializamos el fondo
	call screen_pintar_barraInferior	;Inicializamos la barra inferior de los jugadores.FALTAN COSAS
	
    ; Inicializar la IDT
	call idt_inicializar
	
    ; Cargar IDT
    lidt [IDT_DESC]
	;sti ??
	;int 13						;Generamos una interrupcion de prueba
	call inicializard
	call inicializart
	xor eax,eax
	mov eax, 0x27000 
	shl eax,12
	mov cr3,eax
	xchg bx,bx
	mov eax,cr0
	or eax,0x80000000
	xchg bx,bx
	mov cr0,eax	
	xchg bx,bx
    ; Inicializar el juego

    ; Inicializar pantalla

    ; Inicializar el manejador de memoria

    ; Inicializar el directorio de paginas

    ; Cargar directorio de paginas

    ; Habilitar paginacion

    ; Inicializar tss

    ; Inicializar tss de la tarea Idle

    ; Inicializar el scheduler


    ; Configurar controlador de interrupciones

    ; Cargar tarea inicial

    ; Habilitar interrupciones

    ; Saltar a la primera tarea: Idle

    ; Ciclar infinitamente (por si algo sale mal...)
    mov eax, 0xFFFF
    mov ebx, 0xFFFF
    mov ecx, 0xFFFF
    mov edx, 0xFFFF
    jmp $
    jmp $

;; -------------------------------------------------------------------------- ;;

%include "a20.asm"
