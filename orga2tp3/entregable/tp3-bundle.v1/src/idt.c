
/* ** por compatibilidad se omiten tildes **
================================================================================
 TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
  definicion de las rutinas de atencion de interrupciones
*/

#include "defines.h"
#include "idt.h"
#include "isr.h"

#include "tss.h"

idt_entry idt[255] = { };

idt_descriptor IDT_DESC = {
    sizeof(idt) - 1,
    (unsigned int) &idt
};

/*
    La siguiente es una macro de EJEMPLO para ayudar a armar entradas de
    interrupciones. Para usar, descomentar y completar CORRECTAMENTE los
    atributos y el registro de segmento. Invocarla desde idt_inicializar() de
    la siguiene manera:

    void idt_inicializar() {
        IDT_ENTRY(0);
        ...
        IDT_ENTRY(19);

        ...
    }
*/


#define IDT_ENTRY(numero) \
    idt[numero].offset_0_15 = (unsigned short) ((unsigned int)(&_isr ## numero) & (unsigned int) 0xFFFF);\
    idt[numero].segsel = (unsigned short) 0x50;\
    idt[numero].attr = (unsigned short) 0x8e00; \ //Deberia tener privilegio 3?
    idt[numero].offset_16_31 = (unsigned short) ((unsigned int)(&_isr ## numero) >> 16 & (unsigned int) 0xFFFF);



void idt_inicializar() {
	//usar un for? creo que no anda
    IDT_ENTRY(0);
    IDT_ENTRY(1);
    IDT_ENTRY(2);
    IDT_ENTRY(3);
    IDT_ENTRY(4);
    IDT_ENTRY(5);
    IDT_ENTRY(6);
    IDT_ENTRY(7);
    IDT_ENTRY(8);
    IDT_ENTRY(9);
    IDT_ENTRY(10);
    IDT_ENTRY(11);
    IDT_ENTRY(12);
    IDT_ENTRY(13);
    IDT_ENTRY(14);
    IDT_ENTRY(15);
    IDT_ENTRY(16);
    IDT_ENTRY(17);
    IDT_ENTRY(18);
    IDT_ENTRY(19);
    IDT_ENTRY(20);
    IDT_ENTRY(21);
    IDT_ENTRY(22);
    IDT_ENTRY(23);
    IDT_ENTRY(24);
    IDT_ENTRY(25);
    IDT_ENTRY(26);
    IDT_ENTRY(27);
    IDT_ENTRY(28);
    IDT_ENTRY(29);
    IDT_ENTRY(30);
    IDT_ENTRY(31);
    
    
}
