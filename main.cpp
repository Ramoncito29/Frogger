#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;


// para dibujar, primero tengo que borrar la posicion actual
// acualizar la coodenada
// y finalmente volver a dibujar

void dibujar(int x, int y){
	
	putchxy(x,y,'x');
	
}
	
	void borrar(int x, int y){
		
		// probar comentar
		putchxy(x,y,' ');
		
	}
		
		int main(int argc, char *argv[]) {
			
			cout<<"Con las teclas se mueve (z sale)"<<endl;
			
			int x=60;
			int y=36;
			
			putchxy(x,y,'X'); 
			
			
			
			while(true){
				
				
				if(kbhit()) { 
					int tecla=getch();
					
					switch(tecla)
					{
						
					case 75: //izquierda
						if(x > 12){
							borrar(x,y); 
							x = x - 10;
							dibujar(x,y);	
						};
						
						
						break;
					case 77: //derecha
						
						if(x < 96){
							borrar(x,y); 
							x = x + 10;
							dibujar(x,y); 
						};
						
						
						break;
					case 72: //arriba
						
						borrar(x,y); 
						y = y - 8;
						dibujar(x,y);
						
						
						if(y == 12){
							borrar(x,y); 
							y = 36;
							dibujar(x,y);
						};
						
						break;
					case 80: //abajo
						if(y < 36){
							borrar(x,y); 
							y = y + 8;
							dibujar(x,y);
						};
						
						break;
					case 'z':
						return 1;
					}
					
					putchxy(x,y,'X');
					
				}
				
			}
			return 0;
		}
		
