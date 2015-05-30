/* ** por compatibilidad se omiten tildes **
================================================================================
 TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
  definicion de funciones del manejador de memoria
*/

#include "mmu.h"
#include "i386.h"



/* Atributos paginas */
/* -------------------------------------------------------------------------- */


/* Direcciones fisicas de codigos */
/* -------------------------------------------------------------------------- */
/* En estas direcciones estan los códigos de todas las tareas. De aqui se
 * copiaran al destino indicado por TASK_<i>_CODE_ADDR.
 */

/* Direcciones fisicas de directorios y tablas de paginas del KERNEL */
/* -------------------------------------------------------------------------- */

	


//page_directory=p;
page_entry *page_directory =(page_entry*) (0x27000);
page_entry *page_directory1 =(page_entry*) (0x28000);
page_entry *page_directory2 =(page_entry*) (0x29000);
page_entry *page_directory3 =(page_entry*) (0x2A000);
page_entry *page_directory4 =(page_entry*) (0x2B000);


void inicializard(){

int i;	
page_directory[0] = (page_entry){
		
		(unsigned char)0,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned int)0x28, 	
		};
	
	
	for (i=1;i<1024;i++){
			
		page_directory[i] = (page_entry){
		
		(unsigned char)0,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned int)0, 	
		};
	}

}

void inicializart(){	
int i;

	for (i=0;i<1024;i++){
			
		page_directory1[i] = (page_entry){
		
		(unsigned char)0,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned int)i, 	
		};
	
	}
	/*
	for (i=0;i<1024;i++){
			
		page_directory2[i] = (page_entry){
			
		(unsigned char)1,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned int)i, 	
		};
	
	
	}
	
	for (i=0;i<1024;i++){
			
		page_directory3[i] = (page_entry){
		
		(unsigned char)1,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		
		(unsigned int)i, 	
		};
	
	}
	
	for (i=0;i<1024;i++){
			
		page_directory4[i] = (page_entry){
		
		(unsigned char)1,
		(unsigned char)1,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned char)0,
		(unsigned int)0, 	
		};
	}
	*/ 
	
}
