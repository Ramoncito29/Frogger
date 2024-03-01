#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

class Juego {
public:
	Juego() {
		ranax = 60;
		ranay = 36;
		rana = 'x';
		vx1 = 28;
		vy1 = 28;
		coche = 'y';
		vx2 = 56;
		vx3 = 84;
		vx4 = 84;
		vx5 = 56;
		vx6 = 28;
		vy2 = 20;
		tiempo = clock();
		velocidad = 60;
		paso = 10000 / velocidad;
		dibujar(ranax, ranay, rana);
		dibujar(vx1, vy1, coche);
	}
	
	void run() {
		while (true) {
			if ((paso + tiempo) < clock()) {
				moverVehiculos();
				tiempo = clock();
			}
			
			if (kbhit()) {
				procesarTecla();
			}
		}
	}
	
private:
		int ranax, ranay, vx1, vy1, vx2, vx3, vx4, vx5, vx6, vy2;
		int tiempo, velocidad, paso;
		char rana, coche;
		
		void dibujar(int x, int y, int z) {
			putchxy(x, y, z);
		}
		
		void borrar(int x, int y) {
			putchxy(x, y, ' ');
		}
		
		void moverVehiculos() {
			moverVehiculoDerecha(vx1, vy1);
			moverVehiculoDerecha(vx2, vy1);
			moverVehiculoDerecha(vx3, vy1);
			moverVehiculoIzquierda(vx4, vy2);
			moverVehiculoIzquierda(vx5, vy2);
			moverVehiculoIzquierda(vx6, vy2);
		}
		
		void moverVehiculoDerecha(int& vx, int vy) {
			if (vx == 96) {
				vx = 12;
			}
			
			borrar(vx, vy);
			vx += 4;
			dibujar(vx, vy, coche);
		}
		
		void moverVehiculoIzquierda(int& vx, int vy) {
			if (vx == 12) {
				vx = 96;
			}
			
			borrar(vx, vy);
			vx -= 4;
			dibujar(vx, vy, coche);
		}
		
		void procesarTecla() {
			int tecla = getch();
			
			switch (tecla) {
			case 75:  // izquierda
				if (ranax > 12) {
					borrar(ranax, ranay);
					ranax -= 10;
					dibujar(ranax, ranay, rana);
				}
				break;
			case 77:  // derecha
				if (ranax < 96) {
					borrar(ranax, ranay);
					ranax += 10;
					dibujar(ranax, ranay, rana);
				}
				break;
			case 72:  // arriba
				borrar(ranax, ranay);
				ranay -= 8;
				dibujar(ranax, ranay, rana);
				
				if (ranay == 12) {
					borrar(ranax, ranay);
					ranay = 36;
					ranax = 60;
					dibujar(ranax, ranay, rana);
				}
				break;
			case 80:  // abajo
				if (ranay < 36) {
					borrar(ranax, ranay);
					ranay += 8;
					dibujar(ranax, ranay, rana);
				}
				break;
			default:
				break;
			}
		}
};

int main(int argc, char* argv[]) {
	Juego juego;
	juego.run();
	
	return 0;
}

