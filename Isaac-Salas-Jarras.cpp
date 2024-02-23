 #include <iostream>
 
 using namespace std;
 
 // Declaramos la clase para "Jarra" que tiene una capacidad y el valor actual de agua
 // Mas adelante se definen funciones que puede realizar esta clase
 class Jarra{
 	int capacidad;
 	int valor;
 
 
 // Declaraciones publicas
 public:
 	// Jarra con N litros y vacia al principio
 	Jarra(int n)
 	{
 		capacidad = n;
 		valor = 0;
	}
	 
	 // Funcion de llenado
	 void Llenar()
	 {
	 	valor = capacidad;
	 }
	 
	 //Funcion de vaciado
	 void Vaciar()
	 {
	 	valor = 0;
	 }
	 
	 //Checar si esta llena una jarra
	 bool Lleno()
	 {
	 	return valor >= capacidad;
	 }
	 
	 //Checar si esta vacia una jarra
	 bool Vacio()
	 {
	 	return valor == 0;
	 }
	 
	 //A[B] -> Transferir contenidos de B a A hasta que A este lleno
	 void operator[](Jarra&B)
	 {
	 	int valor_old = valor;
	 	valor = valor + B.valor;
	 	valor = valor > capacidad?capacidad:valor;
	 	
	 	B.valor = B.valor - (valor - valor_old);
	 }
	 
	 // Regresa el valor actual
	 int ValorAct()
	 {
	 	return valor;
	 }
};


int main()
{
	return 0;
}
