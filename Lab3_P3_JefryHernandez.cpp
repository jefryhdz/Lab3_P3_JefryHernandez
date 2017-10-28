#include <iostream>
#include <vector>

using namespace std;

int menu();
int*** ruffini();
int*** crearMatriz(int);
int*** llenar(int***,int);
int** mediana();
bool fechavalida(string);
void print(int***,int);

int main(){
	int resp=4;
	do{
		switch(resp = menu()){
			case 1:
				break;
			case 2: 
				ruffini();
				break;
			case 3: 
				vector<string> fechas;
				char res;
				res='s';
				do{
					string ffecha;
					cout<<"Ingrese la fecha en string "<<endl;
					cin>>ffecha;
					fechas.push_back(ffecha);
					//fecha(ffecha);
					cout<<"Desea ingresar una fecha [s/n]"<<endl;
					cin>>resp;					
				}while(res=='s');
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
	size++;
	matriz = crearMatriz(size);
	llenar(matriz,size);
	print(matriz,size);

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
bool fechavalida(string fecha){


}int*** llenar(int*** matriz,int size){
	for(int i=0;i<size;i++){
		for(int j =0;j<3;j++){
			for(int k=0;k<size;k++){
				matriz[i][j][k]=0;
			}	
		}
	}
	return matriz;
}
void print(int*** matriz,int size){
	 for(int i=0;i<size;i++){
                for(int j =0;j<3;j++){
                        for(int k=0;k<size;k++){
                              cout<<  matriz[i][j][k]<<"|";
                        }cout<<endl;
                }cout<<endl;
	 }	
}
