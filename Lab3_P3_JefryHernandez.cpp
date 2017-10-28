#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int menu();
void ruffini();
int*** crearMatriz(int);
int*** llenar(int***,int,int*);
int** mediana();
bool fechavalida(string);
void print(int***,int);
int* exponentes(int);
int*** calcular(int***,int,int);
void calculardia(string);

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
					int menufecha;
					cout<< "1- Agregar una fecha "<<endl;
					cout<<"2- Listar todo"<<endl;
					cout<<"3- Listar ordenado"<<endl;
					cin>>menufecha;
					switch(menufecha){
						case 1:{
							string ffecha;
							cout<<"Ingrese una fecha"<<endl;
							cin>>ffecha;
							bool date = fechavalida(ffecha);
							if(date){
								calculardia(ffecha);
								fechas.push_back(ffecha);
							}
						}break;
						case 2:{
							for(int i =0;i<fechas.size();i++){
								calculardia(fechas[i]);
							}
						}break;						
						case 3:{
							int a=0,b=0,temp=0;
							for(int i =0;i<fechas.size();i++){
								a= atoi(fechas[i].c_str());
								for(int j=0;j<fechas.size();j++){
									b= atoi(fechas[i].c_str());
									if(b<a){
										string menor="",mayor="";
										menor+=b;
										mayor+=a;
										temp =a;
										fechas[i]=menor;
										fechas[j]=mayor;
									}
								}
							}for(int i =0;i<fechas.size();i++){
								calculardia(fechas[i]);
							}
						}
						break;
					}
					cout<<fechas.size()<<endl;
					cout<<"Desea continuar en el programa de fechas[s/n]"<<endl;
					cin>>res;					
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
void ruffini(){
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
	string ano = fecha.substr(0,4);
	string mes = fecha.substr(4,2);
	string dia = fecha.substr(6,8);
	int year= atoi(ano.c_str());
	int month = atoi(mes.c_str());
	int day= atoi(dia.c_str());
	cout<<year<<" "<<month<<" "<<day<<"sd"<<endl;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>0&&day<32){
			return true;
		}			
	}if(month==4||month==6||month==9||month==11){
		if(day>0&&day<31){		
			return true;
		}else{
			cout<<"fecha no valida"<<endl;
			return false;
		}
	}if(year%4==0){
		if(month==2){
			if(day>0&&day<30){			
				return true;
			}else{
				cout<<"fecha no valida"<<endl;
				return false;
			}
		}	
	}if(year%4!=0&&year%100!=0){
		if(month==2){
			if(day>0&&day<29){
				return true;
			}else{
				cout<<"fecha no valida"<<endl;
				return false;
			}			
		}
	}
	else{
		cout<<"fecha no valida"<<endl;
		return false;
	}


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
void calculardia(string fecha){
	string weekday;
	string ano = fecha.substr(0,4);
	string mes = fecha.substr(4,2);
	string dia = fecha.substr(6,8);
	int year= atoi(ano.c_str());
	int month = atoi(mes.c_str());
	int day= atoi(dia.c_str());
	int a=0,b=0,c=0,d=0,e=0;
	if(year>=1700&&year<1800){
		a=5;
	}if(year>=1800&&year<1900){
		a=3;	
	}if(year>=1900&&year<2000){
		a=1;
	}if(year>=2000&&year<2100){
		a=0;
	}if(year>=2100&&year<2200){
		a=-2;
	}if(year>=2200&&year<2300){
		a=-4;
	}
	string digitos=ano.substr(2,4);//digitos porque ocupo los dos ultimos digitos del año
	int digits = atoi(digitos.c_str());	
	b=digits+(digits/4);
	if(year%4==0&&year%100!=0){
		c=-1;	
	}if(month==1||month==10){
		d=6;
	}if(month==2||month==3||month==11){
		d=2;	
	}if(month==4||month==7){
		d=5;
	}if(month==6){
		d=3;
	}if(month==8){
		d=1;
	}if(month==9||month==12){
		d=4;
	}
	e=day;
	int total=a+b+c+d+e;
	total-=7;
	total%=7;
	if(total ==1){
		weekday="Lunes";
	}if(total==2){
		weekday="Martes";	
	}if(total==3){
		weekday="Miercoles";
	}if(total==4){
		weekday="Jueves";
	}if(total==5){
		weekday="Viernes";
	}if(total==6){
		weekday="Sabado";
	}if(total==0){
		weekday="Domingo";
	}
	string mon;
	if(month==1){
		mon="Enero";
	}if(month==2){
		mon = "Febrero";
	}if(month==3){
		mon ="Marzo";
	}if(month==4){
		mon="Abril";
	}if(month==5){
		mon="Mayo";
	}if(month==6){
		mon="Junio";
	}if(month==7){
		mon="Julio";
	}if(month== 8){
		mon="Agosto";
	}if(month==9){
		mon = "Septiembre";
	}if(month==10){
		mon="Octubre";
	}if(month==11){
		mon="Noviembre";
	}if(month==12){
		mon=="Diciembre";
	}
			

	cout<<weekday<<", "<<day<<" de "<<mon<<" del "<<year<<endl;
}

	
