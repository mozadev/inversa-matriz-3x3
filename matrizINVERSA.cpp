
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10005 //maximo numero de nodos
#define Vertice pair< int , int > //definimos el vertice como un par( first , second ) donde primero es el vertice adyacente y segundo el peso de la arista
#define valorInfinito 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas


struct cmp {
    bool operator() (const Vertice &a , const Vertice &b ) {
        return a.second > b.second;
    }
};
vector< Vertice > ady[ MAX ]; 
int distancia[ MAX ];      
bool visitado[ MAX ];     
priority_queue< Vertice , vector<Vertice> , cmp > Q; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
int nroVertices;                     
int previo[ MAX ];         


void init(){
    for(int i = 0 ; i <= nroVertices ; ++i ){
        distancia[ i ] = valorInfinito;  
        visitado[ i ] = false; 
        previo[ i ] = -1;    
    }
}


void minimizacion(int actual , int adyacente , int peso ){
    
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //minimizamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push(Vertice(adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void impresionVerticesRecorridos(int destino ){
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        impresionVerticesRecorridos(previo[destino]);  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void CaminoMasCorto(int inicial ){
    init(); //inicializamos nuestros arreglos
    Q.push(Vertice(inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        
                minimizacion(actual, adyacente, peso); 
            }
        }
    }


    printf( "Distancia mas cortas iniciando en vertice %d\n" , inicial );
    for(int i = 0 ; i < nroVertices ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }

    puts("\n**************Impresion de camino mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    impresionVerticesRecorridos(destino);
    printf("\n");
}


int main(){
    int a;
    int numArcos , origen, destino , peso , inicial;
    cout<<"\tPrograma para hallar la distancia mas corta de un vertice a otro"<<endl;
    cout<<"Ingrese el numero de vertices: ";
    scanf("%d" , &nroVertices );
    cout<<"Ingrese el numero de aristas: ";
    scanf("%d" , &numArcos );

    cout<<"ingresar el  vertice de origen, vertice siguiente y la distancia o peso de un nodo a otro dejando un espacio entre cada numero"<<endl;


    for (int i = 0; i < numArcos; ++i) {
        scanf("%d %d %d", &origen,&destino,&peso );
        ady[origen].push_back(Vertice(destino, peso));
    }


    cout<<"\tingrese el nodo inicial: "<<endl;
    scanf("%d" , &inicial );
    CaminoMasCorto(inicial);
    return 0;
}

