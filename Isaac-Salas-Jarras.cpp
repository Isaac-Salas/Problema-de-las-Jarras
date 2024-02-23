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

//Funcion para encontrar el Maximo Comun Denominador
int MCD (int n, int m) 
{
	if (m<=n && n%m == 0)
	{
		return m;
	}
	if (n < m)
	{
		return MCD(m,n);
	}
	else
	{
		return MCD(m,n%m);
	}
}

// Verificar la posibilidad de la solucion
bool chequeo (int a, int b, int c)
{
	// Detectectar si el valor que se quiere en una jarra excede la capacidad de A
	if (c>a){
		cout<<"La jarra A no puede ser llenada con mas que su capacidad";
		return false;
	}
	
	// Si c es multiplo de el > de a y de b, entonces es posible
	if (c %MCD(a,b) == 0)
	{
		return true;
	}
	//Si c no es multiplo del ? de a y de b, entonces no es posible
	cout << "No es posible llegar a ese estado con la capacidad de las jarras dadas";
	return false;	
}

// Intentar resolver el problema
void resolver (Jarra A, Jarra B, int resultado)
{
	while (A.ValorAct() != resultado)
	{
		// Posibles casos
		
		//1. A lleno - B vacio
		if (!A.Lleno() && B.Vacio())
		{
			cout << "#Llenar B\n";
			B.Llenar();
			cout << "(A,B) = (" << A.ValorAct() << ", " << B.ValorAct() << ")\n";
		}
		//2. A Lleno
		if (A.Lleno())
		{
			cout << "#Vaciar A\n";
			A.Vaciar();
			cout << "(A,B) = (" << A.ValorAct() << ", " << B.ValorAct() << ")\n";
		}
		
		cout << "#Pasar agua de B -> A\n";
		A[B];
		cout << "(A,B) = (" << A.ValorAct() << ", " << B.ValorAct() << ")\n";
	}
}


int main()
{
	int a, b, resutado;
	cout << "Introduce la capacidad de A: \n";
	cin >> a;
	cout << "Introduce la capacidad de B: \n";
	cin >> b;
	
	do{	
	cout << "Introduce la capacidad deseada de A: \n";
	cin >> resutado;
	}
	while(!chequeo(a,b,resutado));
	
	Jarra A(a), B(b);
	
	cout << "\n\n-Iniciar con: (A,B) = (" << A.ValorAct() << ", " << B.ValorAct() << ")\n\n";
	resolver(A, B, resutado);
	cout << "Listo!"<< endl;

	
	return 0;
}
