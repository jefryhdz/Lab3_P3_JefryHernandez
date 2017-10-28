#include <iostream>
#include <vector>

using namespace std;

int menu();
int*** ruffini();
int*** crearMatriz(int);
int*** llenar(int***,int,int*);
int** mediana();
bool fechavalida(string);
void print(int***,int);
int* exponentes(int);
int*** calcular(int***,int,int);

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
	int* exp;
	int size;
	int a;
	cout<<"Ingrese el mayor grado del exponente"<<endl;
	cin >> size;
	size++;
	matriz = crearMatriz(size);
	exp=exponentes(size);
	llenar(matriz,size,exp);
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<exp[i]<<endl;
	}
	cout<<"Ingrese el valor de a"<<endl;
	cin>>a;
	matriz = calcular(matriz,size,a);
	matriz = calcular(matriz,size,a);
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


}int*** llenar(int*** matriz,int size,int* coeficientes){
	for(int i=0;i<size;i++){
		for(int j =0;j<3;j++){
			if(j!=0){
				for(int k=0;k<size;k++){
					matriz[i][j][k]=0;
				}					
			}if(j==2){
				matriz[i][j][0]=coeficientes[0];
			}
			if(j==0) {
				for(int k=0;k<size;k++){
					matriz[i][j][k]=coeficientes[k];
				}
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
int* exponentes(int size){
	int* exp =new int[size];
	for(int i=size-1;i>=0;i--){
		int coeficiente;
		cout<<"Ingrese el coeficiente para x^"<<i<<endl;
		cin>>coeficiente;
		exp[size-(i+1)]= coeficiente;
	}
	return exp;
}
int*** calcular(int*** matriz,int size,int a){
	for(int i=0;i<size;i++){
                for(int j=0;j<3;j++){
                        if(j==1){
                                for(int k =1;k<=i;k++){
                                        int first = matriz[i][2][k-1];
                                        int second = first*a;
                                        matriz[i][j][k]= second;                                        
                                }
                        }if(j==2){
                                for(int k =0;k<=i;k++){
                                        if(k ==0){
                                                matriz[i][j][k] =matriz[i][0][k];

                                        }
                                        else{
                                                int first = matriz[i][j][k-1];
                                                int second = first*a;
                                                first= matriz[i][0][k];                                                
                                                matriz[i][j][k]= first+second;
                                        }
                                }



                        }
                }
        }
	return matriz;
}
