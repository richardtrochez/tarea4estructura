#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{

//caso base
    if (raiz==NULL)  ///si la raiz es igual a null entonces retorna 0
    return 0;
//cuerpo
if (raiz!=NULL){    /// myi entras la raiz no sea igual a 0 entonces se entra a un ciclo

//    if ()
}


 int sumar_der=suma(raiz->hijo_der);    ///inicion una variable y a la misma vez le asigno un numero que proviene de la recursion de los hijos derechos
 int sumar_izq=suma(raiz->hijo_izq);    ///inicion una variable y a la misma vez le asigno un numero que proviene de la recursion de los hijos izqierdos

 return raiz->num+sumar_der+sumar_izq;   /// regreso un numero la suma de mi raiz+los hijos de mi derecha y + la suma de los hijos a mi izuierda

/// me cuento yo y cuento cada uno de mis hijos a la derecha y la izwuierda
}


//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    if (raiz==NULL)          ///tipica caso base si raiz===0 entonces que retorne 0
        return 0;

    int contar_der=cantidadNodos(raiz->hijo_der);          ///si no creo una variable para contar mis hijos derechos y otra para los izquierdos
    int contar_izq=cantidadNodos(raiz->hijo_izq);       /// para moverme por el arobol utilizo la recursion y retorno la suma de la cantdad de nodos de la derecha+ los de la izquierda.


    return 1+contar_der+contar_izq;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{

    //caso base
    if (raiz==NULL)  ///caso base si la raiz es igual a 0 entoces retorno 0
    return 0;
    int contar_der=cantidadNodos(raiz->hijo_der);   ///creo dos variables para contar la cantidad de nodos de mi arbol
    int contar_izq=cantidadNodos(raiz->hijo_izq);

    int contar_total=1+contar_der+contar_izq;   /// sumo la cantidad de mis nodos con el metodo me cuento yo y cada uno de mis hijos

 int sumar_der=suma(raiz->hijo_der);          ///creo 2 variables que vallan sumando recursivamente los datos almacenados en el arbol
 int sumar_izq=suma(raiz->hijo_izq);

 int total_suma=raiz->num+sumar_der+sumar_izq;   /// sumo y hago un solo total de la cantidad de datos en el arbol

 int promedio=total_suma/contar_total;      ///saco el promedio dividiento el gran total de mi suma entre la cantidad de nodos que existen en el arbol.

return promedio;   ///retorno el promedio
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7 )
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
if (raiz==NULL)    /// ejercicio realizado con Richard Murcia, ///si raiz es null entonces que retorne 1 ua que contamos solo 1 nodo
    return 1;
if (raiz->num==num)  /// de igual forma si la raiz es el numero que buscamos entonces que retorne 1
    return 1;

int contador=1; /// de lo contrario si el valor esta en nuestros hijos iniciamos un contador que valla acumulando la cantidad de nodos que se han recorrido


    if (num>raiz->num)   /// si el numero buscado es mayor al dato almacenado  en la raiz entonces quiere decir que mi el dato esa a la derecha y lo suma en el contador
     {
     contador+=cuantosPasos(raiz->hijo_der,num);  ///funcion recursiva que recorre mis hijos derechos contandolos.

     }
        if (num<raiz->num)  /// esta informacion es lo arriba descrito con la excepcion que cuento mis hijos derechos
          {
          contador+=cuantosPasos(raiz->hijo_izq,num);
          }
return contador;

///al finalizar mi recorrido por el arbol por la izqierda por la derecha y por mis subraices devuelvo cuantos nodos tuve que pasar para encontrar el dato
}


//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
    if (raiz==NULL)        ///caso base
    return 0;
          if ((raiz->hijo_der==NULL) && (raiz->hijo_izq==NULL))   ///una hoja es aquella en donde los hijos apuntan (ambos hacia null)
          return 1;                ///evaluo caada uno de mis hijos. si estos estan apuntando anull retornna 1, de lo contrario devuelvo la cantidad de hojas
          /// empleando un metodo de recuersion que me cuente solo los hijos que apunto a null/

  else

    return sumaHojas(raiz->hijo_der)+sumaHojas(raiz->hijo_izq);

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}




/*
//si se quiere usar un list usar un iterador, un arreglo debemos hacer un arreglo aparte // si queremos un set // si queremos un apuntador a mi primero hijo Nodo* primer_hijo, Nodo* sig;
using namespace std;

class Nodo
{
    public:
    int dato;
    string dato2;
    vector<Nodo*>hijos;
    Nodo(int dato,string dato2)
    {
        this->dato = dato;
        this->dato2=dato2;
    }

};

void imprimir(Nodo* raiz)
{
    if(raiz == NULL)
    return;

    cout<<raiz->dato<<endl;
    for(int i=0; i<raiz->hijos.size();i++)
    {
    imprimir(raiz->hijos[i]);
    }
}

Nodo* buscar(Nodo* raiz, int dato)
{

//si todo es null
   if (raiz==NULL)
   return NULL;

//si el valor lo encontre
    if (raiz->dato==dato)
    return raiz;


//si uno de mis hijos tiene el encontrado
       for(int i=0;i<raiz->hijos.size();i++)
       {

       Nodo* buscado=buscar(raiz->hijos[i],dato);
             if (buscado!=NULL)
             return buscado;
        }

return NULL;
}


Nodo* getMayor(Nodo* raiz)
{
      //caso base:
      if (raiz==NULL)
      return NULL;

      Nodo* mayor=raiz;

    for (int i=0;i<raiz->hijos.size();i++)
    {
        //encontrar el mayor de mis hijos
        Nodo* mayor_hijo= getMayor(raiz->hijos[i]);
        if  (mayor_hijo->dato > mayor->dato)
        mayor =mayor_hijo;


    }

     return mayor;
}

int main()
{
    Nodo* n1 = new Nodo(16,"A");
    Nodo* n2 = new Nodo(2,"B");
    Nodo* n3 = new Nodo(3,"C");
    Nodo* n4 = new Nodo(4,"C");
    Nodo* n5 = new Nodo(5,"D");
    Nodo* n6 = new Nodo(6,"E");
    Nodo* n7 = new Nodo(7,"F");

    n1->hijos.push_back(n2);
    n1->hijos.push_back(n3);
    n1->hijos.push_back(n4);

    n2->hijos.push_back(n5);
    n2->hijos.push_back(n6);

    n4->hijos.push_back(n7);

    //imprimir(n1);

    //Nodo* buscado=buscar(n1,5);

    Nodo* mayor=getMayor(n1,10);
    cout<mayor->dato<<endl;
   // cout<<mayor->dato<<end;
    //cout<<buscado->dato<<endl;
    //cout<<buscado->dato2<<endl;

    return 0;
}
*/
