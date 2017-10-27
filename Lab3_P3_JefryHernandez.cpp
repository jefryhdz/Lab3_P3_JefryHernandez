#include <iostream>
#include <vector>

using namespace std;

int menu();
int*** ruffini();
int*** crearMatriz(int);

int main(){
	int resp=4;
	do{
		switch(resp = menu()){
			case 1:
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4:
				break;
		}	

	}while(resp!=4);	
	return 0;
}

int menu(){
	int resp;
	cout<<"1-Podar y buscar"<<endl;
	cout<<"2-Ruffini"<<endl;
	cout<<"3-Fecha"<<endl;
	cout<<"4-Salir"<<endl;
	cin>>resp;
	return resp;
}
int*** ruffini(){
	int*** matriz;
	int size;
	cout<<"Ingrese el mayor grado del exponente"<<endl;
	cin >> size;
	matriz = crearMatriz(size);
}
int*** crearMatriz(int size){
	int*** matriz = new int **[size];
	for(int i =0;i<size;i++){
		matriz[i]= new int*[3];		
	}
	for(int i=0;i<size;i++){
		for(int j =0; j<size;j++){
			matriz[i][j] = new int[size];
		}	
	}
	return matriz;
}
