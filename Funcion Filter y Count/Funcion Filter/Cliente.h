typedef struct{
 int dia;
 int mes;
 int anio;
}eFecha;

typedef struct{
  int ID_Cliente;
  eFecha fecha;
  int ID_Llamada;
  int ID_Problema;
  char Solucion[2];

}Cliente;

Cliente* cliente_newParametros(char* idLlamadaStr,char* diaStr,char* mesStr, char* anioStr,char* numeroClienteStr, char* idProblemaStr, char* solucionStr);
Cliente* cliente_new();

int funcionProblemaUno (void* element);
int funcionProblemaDos (void* element);
int funcionProblemaTres (void* element);
int funcionProblemaCuatro (void* element);
int funcionProblemaCinco (void* element);

int Cliente_showClientes(Cliente* pArrayListCliente, int sizeList);

int cliente_setIdLlamada(Cliente* this,int idLlamada);
int cliente_getIdLLamada(Cliente* this,int* idLlamada);

int cliente_setDia(Cliente* this,int dia);
int cliente_getDia(Cliente* this,int* dia);

int cliente_setMes(Cliente* this,int mes);
int cliente_getMes(Cliente* this,int* mes);

int cliente_setAnio(Cliente* this,int anio);
int cliente_getAnio(Cliente* this,int* anio);

int cliente_setNumeroCliente(Cliente* this,int numeroCliente);
int cliente_getNumeroCliente(Cliente* this,int* numeroCliente);

int cliente_setIdProblema(Cliente* this,int idProblema);
int cliente_getIdProblema(Cliente* this,int* idProblema);

int cliente_setSolucion(Cliente* this,char* solucion);
int cliente_getSolucion(Cliente* this,char* solucion);

int ordenarLlamadaPorId( void* emp1, void* emp2);

void problemaEnFormatoTexto(int idProblema,char* problemaStr);
int FuncionFiltrarIdClienteMayorA30YProblema1SinSolucion(void* element);

int funcionContar(void* element);
