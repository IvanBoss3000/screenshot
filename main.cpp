#include "common.h"
#include "Funkies.h"

using namespace std;

int main(int argc, char *argv[]) {

	std::string commands[4] = {"--set-mouse", "--move-mouse", "--screenshot", "--get-mouse"}; 
	
	if ( argc <= 1) {
		cout << "Usage: screenshot [option] args\n\t--get-mouse\n\t--set-mouse [x] [y] \n\t--move-mouse [x] [y] \n\t--screenshot [x] [y] [name].bmp\n";
		return 0;
	}
	
	for (int i = 0; i < argc - 1; i++) {

		for (int c = 0; sizeof(commands) / sizeof(commands[0]) > c; c++) {

			if ( string(argv[i + 1]) == string(commands[c]) ) {

				switch (c + 1){

					case 1: //--set-mouse
						
						setMousePos(atoi(argv[i + 2]), (atoi(argv[i + 3])));

						break;

					case 2: //--move-mouse

						moveMousePos(atoi(argv[i + 2]), (atoi(argv[i + 3])));
						break;

					case 3: //--screenshot

						screenCapturePart(0, 0, atoi(argv[i + 2]), atoi(argv[i + 3]), argv[i + 4]);
						break;

					case 4: //--get-mouse

						POINT xyPos;
						GetCursorPos(&xyPos);
						cout << xyPos.x << "|" << xyPos.y << endl;
						break;
				}
			}
		}
	}
	return 0;
}

