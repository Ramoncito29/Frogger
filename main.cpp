#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;


// para dibujar, primero tengo que borrar la posicion actual
// acualizar la coodenada
// y finalmente volver a dibujar

void dibujar(int x, int y, int z){
	
	putchxy(x,y,z);
	
}
	
		
	void borrar(int x, int y){
		
		// probar comentar
		putchxy(x,y, ' ');
		
	}
		
		int main(int argc, char *argv[]) {
			
			cout<<"Con las teclas se mueve (z sale)"<<endl;
			
			int x=60;
			int y=36;
			int rana = 'x';
			putchxy(x,y,rana); 
			
			int vx = 12;
			int vy = 28;
			int coche = 'y';
			putchxy(vx,vy,coche);
			
			
			int tiempo = clock();
			int velocidad =60;
			int paso =	10000/velocidad;
			
			
			
			
			
			while(true){
				
				if((paso + tiempo) < clock()){
					if(vx == 96){
						vx = 12;
					};
					
					putchxy(vx,vy, ' ');
					vx = vx + 4;
					putchxy(vx,vy,coche);
					tiempo = clock();
				};
				
				if(kbhit()) { 
					int tecla=getch();
					
					switch(tecla)
					{
						
					case 75: //izquierda
						if(x > 12){
							borrar(x,y); 
							x = x - 10;
							dibujar(x,y,rana);	
						};
						
						
						break;
					case 77: //derecha
						
						if(x < 96){
						borrar(x,y); 
						x = x + 10;
						dibujar(x,y,rana); 
						};
						
						
						break;
					case 72: //arriba
						
						borrar(x,y); 
						y = y - 8;
						dibujar(x,y,rana);
						
						
						if(y == 12){
							borrar(x,y); 
							y = 36;
							dibujar(x,y,rana);
						};
						
						break;
					case 80: //abajo
						if(y < 36){
						borrar(x,y); 
						y = y + 8;
						dibujar(x,y,rana);
						};
						
						break;
					case 'z':
						return 1;
					}
					
										
				}
				
			}
			
				
					
						
			return 0;
		}
