/* ** por compatibilidad se omiten tildes **
================================================================================
 TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
  definicion de funciones del manejador de memoria
*/

#ifndef __MMU_H__
#define __MMU_H__

#include "defines.h"
#include "game.h"

#define CODIGO_BASE       0X400000

#define MAPA_BASE_FISICA  0x500000
#define MAPA_BASE_VIRTUAL 0x800000

void mmu_inicializar();
void inicializard();
void inicializart();

typedef struct str_page_entry{
	
	unsigned char p:1;
	unsigned char r_W:1;
	unsigned char us:1;
	unsigned char pwt:1;
	unsigned char pcd:1;
	unsigned char a:1;
	unsigned char cero:1;
	unsigned char ps:1;
	unsigned char g:1;
	unsigned char disp1:1;
	unsigned char disp2:1;
	unsigned char disp3:1;
	unsigned int base_0_19:20;	
			
}__attribute__((__packed__,aligned(4)))page_entry;







#endif	/* !__MMU_H__ */
