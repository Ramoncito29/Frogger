#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;




	
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
			
			int vx1 = 28;
			int vy1 = 28;
			int coche = 'y';
			putchxy(vx1,vy1,coche);
			
			int vx2 = 56;
					
			int vx3 = 84;
			
			int vx4 = 84;
				
			int vx5 = 56;
			
			int vx6 = 28;
			
			int vy2 = 20;
		
			
			putchxy(vx2,vy1,coche);
			putchxy(vx3,vy1,coche);
			
			int tiempo = clock();
			int velocidad =60;
			int paso =	10000/velocidad;
			
			
			
//			
			
			
			
			while(true){
				//primera linea
				if((paso + tiempo) < clock()){
					if(vx1 == 96){
						vx1 = 12;
					};
					
					putchxy(vx1,vy1, ' ');
					vx1 = vx1 + 4;
					putchxy(vx1,vy1, coche);
					tiempo = clock();
					
					if(vx2 == 96){
						vx2 = 12;
					};
					
					putchxy(vx2,vy1, ' ');
					vx2 = vx2 + 4;
					putchxy(vx2,vy1, coche);
					tiempo = clock();
					
					if(vx3 == 96){
						vx3 = 12;
					};
					
					putchxy(vx3,vy1, ' ');
					vx3 = vx3 + 4;
					putchxy(vx3,vy1, coche);
					tiempo = clock();
					//segunda linea
					
					if(vx4 == 12){
						vx4 = 96;
					};
					
					putchxy(vx4,vy2, ' ');
					vx4 = vx4 - 4;
					putchxy(vx4,vy2, coche);
					tiempo = clock();
////					
					if(vx5 == 12){
						vx5 = 96;
					};
					
					putchxy(vx5,vy2, ' ');
					vx5 = vx5 - 4;
					putchxy(vx5,vy2, coche);
					tiempo = clock();
					
					if(vx6 == 12){
						vx6 = 96;
					};
					
					putchxy(vx6,vy2, ' ');
					vx6 = vx6 - 4;
					putchxy(vx6,vy2, coche);
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
						
						return 1;
					}
					
										
				}
				
			}
			
					
						
			return 0;
		}
