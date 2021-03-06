/* ** por compatibilidad se omiten tildes **
================================================================================
TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
definicion de funciones del scheduler
*/

#include "screen.h"
#include "game.h"


extern jugador_t jugadorA, jugadorB;

//no entiendo este  casteo, o lo que sea
static ca (*p)[VIDEO_COLS] = (ca (*)[VIDEO_COLS]) VIDEO;

const char reloj[] = "|/-\\";
#define reloj_size 4


void screen_actualizar_reloj_global()
{
    static uint reloj_global = 0;

    reloj_global = (reloj_global + 1) % reloj_size;

    screen_pintar(reloj[reloj_global], C_BW, 49, 79);
}

void screen_pintar(uchar c, uchar color, uint fila, uint columna)
{
    p[fila][columna].c = c;
    p[fila][columna].a = color;
}

void screen_pintar_fondo()
{
	int i,j;
	char f = 0x00;
	for(i=0;i<VIDEO_FILS;i++){
		for(j=0;j<VIDEO_COLS;j++)
			screen_pintar(f,0x70,i,j);
	}	

}

void screen_pintar_barraInferior()
{
	int i;
	
	//Barra NEGRA:
	for(i=BARRA_NEGRA_POS;i<BARRA_NEGRA_POS+BARRA_NEGRA_HEIGHT;i++)
		screen_pintar_linea_h(0,0,i,0,80);
	
	//Rectangulo ROJO 7x5
	for(i=RECT_ROJO_POS;i<RECT_ROJO_POS+RECT_HEIGHT;i++)
		screen_pintar_linea_h(0,0x40,i,VIDEO_COLS/2-RECT_WIDTH,RECT_WIDTH);
	
	//Cuadrado AZUL		 7x5
	for(i=RECT_AZUL_POS;i<RECT_AZUL_POS+RECT_HEIGHT;i++)
		screen_pintar_linea_h(0,0x10,i,VIDEO_COLS/2,RECT_WIDTH);
				
	//MAS COSAS...
	
}


void screen_pintar_linea_v(unsigned char c, unsigned char color, int fila, int columna, int alto)
{	
	int i;	
	for(i=fila;i<fila+alto;i++)
		screen_pintar(c,color,i,columna);
	
}

void screen_pintar_linea_h(unsigned char c, unsigned char color, int fila, int columna, int ancho)
{	
	
	int j;	
	for(j=columna;j<columna+ancho;j++)
		screen_pintar(c,color,fila,j);
	
}

uchar screen_valor_actual(uint fila, uint columna)
{
    return p[fila][columna].c;
}

void print(const char * text, uint x, uint y, unsigned short attr) {
    int i;
    for (i = 0; text[i] != 0; i++)
     {
        screen_pintar(text[i], attr, y, x);

        x++;
        if (x == VIDEO_COLS) {
            x = 0;
            y++;
        }
    }
}

void print_hex(uint numero, int size, uint x, uint y, unsigned short attr) {
    int i;
    char hexa[8];
    char letras[16] = "0123456789ABCDEF";
    hexa[0] = letras[ ( numero & 0x0000000F ) >> 0  ];
    hexa[1] = letras[ ( numero & 0x000000F0 ) >> 4  ];
    hexa[2] = letras[ ( numero & 0x00000F00 ) >> 8  ];
    hexa[3] = letras[ ( numero & 0x0000F000 ) >> 12 ];
    hexa[4] = letras[ ( numero & 0x000F0000 ) >> 16 ];
    hexa[5] = letras[ ( numero & 0x00F00000 ) >> 20 ];
    hexa[6] = letras[ ( numero & 0x0F000000 ) >> 24 ];
    hexa[7] = letras[ ( numero & 0xF0000000 ) >> 28 ];
    for(i = 0; i < size; i++) {
        p[y][x + size - i - 1].c = hexa[i];
        p[y][x + size - i - 1].a = attr;
    }
}

void print_dec(uint numero, int size, uint x, uint y, unsigned short attr) {
    int i;
    char letras[16] = "0123456789";

    for(i = 0; i < size; i++) {
        int resto  = numero % 10;
        numero = numero / 10;
        p[y][x + size - i - 1].c = letras[resto];
        p[y][x + size - i - 1].a = attr;
    }
}


