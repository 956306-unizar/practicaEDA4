/*
 * =================================
 * AUTORES DEL CÓDIGO Y SUS NIPS
 * =================================
 * Arián Lajara Bueno   - 798618
 * Abel Martínez Zárate - 956306
 * David Maza Luengo    - 956269
 * =================================
 */

#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include "fecha.hpp"
#include "pila_v3.hpp"
#include <string>
using namespace std;

// PREDECLARACION DEL TAD GENERICO coleccionITF--------------------------------------------------------------------------

//usa booleanos, naturales, cadenas, fechas

/* 
   Los valores del TAD coleccionITF representan una colleción de Items Temáticos Fechados (T),
   con identificadores no repetidos, guardando estos en la agrupación de forma ordenada lexicográficamente.
   Además cuenta con un iterador para recorrer en orden la colección. 
   
   Los Items Temáticos Fechados T necesitan de las siguientes operaciones:
    -identificador: devuelve un string con el identificador del item
        string identificador(const T &i);

    -tema: devuelve una cadena con el tema del Item
        string tema(const T &i);

    -fecha: devuelve un tipo fecha asociada al Item
        Fecha fecha(const T &i);
*/
template<typename T> struct ColeccionITF;

//operaciones--------------------------------------------------------------------------------------

/*
    Crea una colección de ITF vacía, sin ítems.
*/
template<typename T> void crear(ColeccionITF<T> &c);
 

/*
    Si en c no hay ningún ítem con identificador igual al de i, añade
    el ítem i a la colección c. En caso contrario, c no cambia.
*/
template<typename T> void anadir(ColeccionITF<T> &c, const T &i);


/*
    Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a c. En
    caso contrario, devuelve una colección igual a la resultante de sustituir en c el ítem que tenía
    identificador igual al de i, por el ítem i.
*/
template<typename T> void actualizar(ColeccionITF<T> &c, const T &i);


/*
    Si en c hay algún ítem con identificador(único; no repetido) igual a ident, borra ese item de c.
    En caso contrario, c se queda como está.

    NUNCA USAR UN ITERADOR YA INICIADO DESPUÉS DE BORRAR UN ELEMENTO - VOLVER A INICIAR ITERADOR
*/
template<typename T> void borrar(const string &ident, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename T> bool esta(const string &ident, const ColeccionITF<T> &c);


/*
    Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
    PARCIAL: operación no definida si en c no hay ningún ítem con identificador igual a ident.
*/
template<typename T> T obtenerITF(const string &ident, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename T> string obsoletos(const Fecha &f, const string &separador, const ColeccionITF<T> &c);
 

/*
    Elimina de c todos los ítems con fecha estrictamente anterior a f.
*/
template<typename T> void purgar(const Fecha &f, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem con tema igual a t.
*/
template<typename T> bool existeTema(const string &t, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con tema igual a t, y separados entre sí por la cadena separador.
*/
template<typename T> string delTema(const string &t, const string &separador, const ColeccionITF<T> &c);


/*
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t.
*/
template<typename T> void zanjarTema(const string &t, ColeccionITF<T> &c);



/*
    Devuelve verdad si y sólo si c no contiene ningún ítem.
*/
template<typename T> bool esVacia(const ColeccionITF<T> &c);


/*
    Devuelve el número de ítems que hay en la colección c.
*/
template<typename T> int tamano(const ColeccionITF<T> &c);


//OPERACIONES DEL ITERADOR-----------------------------------------------------------
/*
Las siguientes operaciones constituyen un iterador que permite visitar los elementos de la
colección de forma que siempre se visiten antes los elementos con identificador anterior (i.e.
lexicográficamente menor) a los que se visitarán más tarde:
*/

/*
    Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
    ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
    haber visitado ningún ítem).
*/
template<typename T> void iniciarIterador(ColeccionITF<T> &c);


/*
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
    falso si ya se ha visitado el último ítem.
*/
template<typename T> bool existeSiguiente(const ColeccionITF<T> &c);


/*
    Si existe un elemento por visitar en c devuelve TRUE, devuelve dicho elemento por e y avanza el iterador.
    Si no, devuelve falso y e se queda como estaba.
*/
template<typename T> bool siguienteYavanza(ColeccionITF<T> &c, T &e);


// FIN INTERFAZ ==============================================================================================================

//PREDECLARACIÓN FUNCIONES AUXILIARES
template<typename T> void borrarRec(const string &ident, typename ColeccionITF<T>::Nodo* &raiz, bool &borrado);
template<typename T> void borrarMax(typename ColeccionITF<T>::Nodo* &raiz, T &dato);

template<typename T> void anadirRec(typename ColeccionITF<T>::Nodo* &raiz, const T &item, bool &anadido);

template<typename T> void purgarPostOren(const Fecha &fLim, ColeccionITF<T> &c, typename ColeccionITF<T>::Nodo* &raiz);

template<typename T> void existeTemaPreOren(const string &t, const typename ColeccionITF<T>::Nodo* raiz, bool &encontrado);

// DECLARACION DEL TIPO GENERICO coleccionITF
template<typename T> struct ColeccionITF{

    friend void crear<T>(ColeccionITF<T> &c);
    friend void anadir<T>(ColeccionITF<T> &c, const T &i);
    friend void actualizar<T>(ColeccionITF<T> &c, const T &i);
    friend void borrar<T>(const string &ident, ColeccionITF<T> &c);
    friend bool esta<T>(const string &ident, const ColeccionITF<T> &c);
    friend T obtenerITF<T>(const string &ident, const ColeccionITF<T> &c);
    friend string obsoletos<T>(const Fecha &f, const string &separador, const ColeccionITF<T> &c);
    friend void purgar<T>(const Fecha &f, ColeccionITF<T> &c);
    friend bool existeTema<T>(const string &t, const ColeccionITF<T> &c);
    friend string delTema<T>(const string &t, const string &separador, const ColeccionITF<T> &c);
    friend void zanjarTema<T>(const string &t, ColeccionITF<T> &c);
    friend bool esVacia<T>(const ColeccionITF<T> &c);
    friend int tamano<T>(const ColeccionITF<T> &c);

    friend void iniciarIterador<T>(ColeccionITF<T> &c);
    friend bool existeSiguiente<T>(const ColeccionITF<T> &c);
    friend bool siguienteYavanza<T>(ColeccionITF<T> &c, T &e);


    private: //declaracion de la representacion interna del tipo
       /*
        Árbol Binario de Búsqueda en memoria dinámica.
        "raiz" es un puntero apunta al primer nodo del árbol (la raíz). Si la colección está vacía apuntará a NIL.
        "nElem" lleva la cuenta de cuantos elementos hay en la colección.
        "iter" es una pila que servirá como iterador.

        "Nodo" es un contenedor para el tipo de dato T, un puntero al hijo izquierdo del nodo del árbol y otro
        a su hijo derecho. Si sus hijos son vacíos apuntarán a NIL respectivamente.
        */
       
       //llamar a nodos asi: typename ColeccionITF<T>::Nodo
        struct Nodo{
            T dato;
            Nodo* izq;
            Nodo* der;
        };
        
        typedef Nodo* abb;  //tipo PUNTERO A NODO es lo mismo que tipo ABB

        abb raiz;
        int nElem;
        
        //CAMPOS ITERADOR
        Pila<abb> iter;


        //FRIEND FUNCIONES AUXILIARES
        friend void borrarRec<T>(const string &ident, typename ColeccionITF<T>::Nodo* &raiz, bool &borrado);
        friend void borrarMax<T>(typename ColeccionITF<T>::Nodo* &raiz, T &dato);
        friend void anadirRec<T>(typename ColeccionITF<T>::Nodo* &raiz, const T &item, bool &anadido);
        friend void purgarPostOren<T>(const Fecha &fLim, ColeccionITF<T> &c, typename ColeccionITF<T>::Nodo* &raiz);
        friend void existeTemaPreOren<T>(const string &t, const typename ColeccionITF<T>::Nodo* raiz, bool &encontrado);
};


//IMPLEMENTACION DE LAS OPERACIONES DEL TAD GENERICO coleccionITF=============================================================================

/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Crea una colección de ITF vacía, sin ítems.
*/
template<typename T>
void crear(ColeccionITF<T> &c)
{
    c.raiz = nullptr;
    c.nElem = 0;
    crearVacia(c.iter);
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Si en c no hay ningún ítem con identificador igual al de i, añade
    el ítem i a la colección c respetando la definición de abb. En caso contrario, c no cambia.

    Además actualizara nElem apropiadamente.
*/
template<typename T> 
void anadir(ColeccionITF<T> &c, const T &i)
{    
    bool anadido = false;
    anadirRec<T>(c.raiz, i, anadido);
    if(anadido){
        c.nElem++;
    }
}


/*
    Función auxiliar recursiva de anadir. Recorre (siguiendo la definición de abb) el árbol raiz en busca de una hoja 
    a la cual insertarle un hijo cuyo dato sea item. Si encuentra un nodo cuyo dato tenga identificador igual al de item,
    deja de buscar y anadido queda a false. En caso contrario se insertatá correctamente y anadido quedara a true.
*/
template<typename T> 
void anadirRec(typename ColeccionITF<T>::Nodo* &raiz, const T &item, bool &anadido){

    if(raiz == nullptr){    //CASO BASE -- hemos llegado al punto de inserción

        raiz = new typename ColeccionITF<T>::Nodo;  //hacemos espacio en memoria para el nodo
        raiz->dato = item;         //configuramos sus valores
        raiz->der = nullptr;
        raiz->izq = nullptr;
        anadido = true;         //para aumentar nElem

    }else{      //CASO (quizas) RECURSIVO -- hay que seguir buscando un hijo vacío donde ponderlo

        if( identificador(item) < identificador(raiz->dato) ){  //id item < id nodo actual -> hijo izq
            anadirRec<T>(raiz->izq, item, anadido);

        }else if( identificador(item) > identificador(raiz->dato) ){ //id item > id nodo actual -> hijo dcho
            anadirRec<T>(raiz->der, item, anadido);

        }else{  //id item == id nodo actual -> no añadir, eso es cosa de actualizar()
            anadido = false;    //FIN DE LA RECUSIVIDAD y devuelve falso
        }
    }

}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Busca si existe un dato de tipo T, en los nodos que almacena la coleccionITF, que tenga el mismo identificador que el dato de tipo T
    proporcionado (i). De ser así, el dato que ya se encuentra en la coleccionITF se actualizará con el del parámetro i.
    Al solo cambiarse el valor de la variable "dato" dentro del nodo que se encuentra en dicha posición, no hará falta hacer más cambios
    en ninguna otra parte.
*/
template<typename T> 
void actualizar(ColeccionITF<T> &c, const T &i) {
    /*
    // Cualquier caso posible menos el de lista vacía que nos quedaremos igual
    if(c.primero != nullptr) {

        string identificadorDelNuevoDato = identificador(i);

        // Creamos un puntero al primer nodo para comenzar el recorrido de busqueda
        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        while (pAux->sig != nullptr && identificador(pAux->dato) < identificadorDelNuevoDato)
        {
            pAux = pAux->sig;
        }

        if (identificador(pAux->dato) == identificadorDelNuevoDato)
        {
            pAux->dato = i;
        }
    }
    */
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Si en c hay algún ítem con identificador(único; no repetido) igual a ident, borra ese item de c.
    En caso contrario, c se queda como está.

    También se encarga de actualizar nElem.
    
    NUNCA USAR UN ITERADOR YA INICIADO DESPUÉS DE BORRAR UN ELEMENTO
    Si el puntero al elemento X se encuentra en la pila del iterador y X se borra, el puntero en la pila
    estará apuntando a una direccion de memoria liberada, lo que es una violación de acceso si se usa.
*/
template<typename T> 
void borrar(const string &ident, ColeccionITF<T> &c)
{      
    bool borrado = false;
    borrarRec<T>(ident, c.raiz, borrado);
    if(borrado){
        c.nElem--;
    }
}


/*
    Función auxiliar recursiva de borrar Y purgarPostOrden. Recorre en preOrden el árbol "raiz" en busca de un nodo con identificador de su dato == ident.
    Si lo encuentra, borra el dato, respetando la definición de abb, y deja de buscar, dejando borrado a true. Si no lo encuentra después
    de recorrer todo el arbol, deja borrado a false;
*/
template<typename T>
void borrarRec(const string &ident, typename ColeccionITF<T>::Nodo* &raiz, bool &borrado){
    if(raiz != nullptr && !borrado){    //no hay repeticiones - en q se borre 1 PARAR
        
        if(ident == suIdentificador(raiz->dato) ){ //es este elemento -- CASO BASE -- borrar
            //el comportamiento depende de que hijos tenga o no
            typename ColeccionITF<T>::abb aux;

            if(raiz->izq == nullptr){   //no tiene hijo izquierdo(hijo dcho unknown)
                //su hijo derecho será la nueva raiz sin romper la estructura de abb (si es nil también será correcto)
                aux = raiz;
                raiz = raiz->der;
                delete(aux);


            }else if(raiz->der == nullptr){ //tiene hijo izquierdo PERO NO DERECHO
                //su hijo izquierdo será la nueva raiz sin romper la estructura de abb
                aux = raiz;
                raiz = raiz->izq;
                delete(aux);

            }else{  //tiene dos hijos -> la nueva raiz será o el máximo del hijo izquierdo o el mínimo del hijo derecho para respetar el abb
                //el max del hijo izqdo - su más derecho               
                borrarMax<T>(raiz->izq, raiz->dato);
            }
            borrado = true;    //para actualizar nElem en la funcion borrar()

        }else if(ident < suIdentificador(raiz->dato) ){    //estara por el arbol izdo
            //llamada recursiva a borrar en el hijo izdo
            borrarRec<T>(ident, raiz->izq, borrado);

        }else{  //estara por el arbol dcho
            //llamada recursiva a borrar en el hijo dcho
            borrarRec<T>(ident, raiz->der,borrado);

        }
    }else{
        borrado = false;
    }
}


/*
    Función auxiliar recursiva de borrarRec. Raiz será inicialmente el hijo izquierdo del elemento a borrar E, y dato el dato de E.
    borrarMax encontrará el máximo del subarbol izquierdo de E, intercambiará el dato de E por el máximo del subar. izq. y borrá ese elemento.
*/
template<typename T>
void borrarMax(typename ColeccionITF<T>::Nodo* &raiz, T &dato){

    typename ColeccionITF<T>::abb aux;

    if(raiz->der == nullptr){   //CASO BASE -- si no hay hijo derecho, ya tenemos el máximo
        //la nueva raiz es el primer hijo izquierdo -> como no hay hijo dcho seguirá respetando la definicion de abb
        dato = raiz->dato;
        aux = raiz;
        raiz = raiz->izq;
        delete(aux);

    }else{  //CASO REC -- seguir buscando el máximo bajando por el derecho
        borrarMax(raiz->der, dato);
    }
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve verdad si y sólo si en c hay algún ítem con identificador igual al parámetro ident.
    Para ello, recorre toda la colección hasta encontrar el elemento, donde no buscará más y se saldrá,
    o hasta que llegue al fin de la colección, significando que no encontró el elemento en la colección.
*/
template<typename T>
bool esta(const string &ident, const ColeccionITF<T> &c) {

    /*
    bool estaEnColeccion = false;

    bool busquedaAunValida = true;

    if(c.primero != nullptr){

        typename ColeccionITF<T>::Nodo* pAux = c.primero;
        string identificadorActual;

        while(pAux != nullptr && !estaEnColeccion && busquedaAunValida) {

            identificadorActual = identificador(pAux->dato);

            if(ident < identificadorActual) {

                busquedaAunValida = false;

            } else if(ident == identificadorActual) {

                estaEnColeccion = true;

            } else {

                pAux = pAux->sig;

            }

        }

    }

    return estaEnColeccion;
    */

}

/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve el elemento de tipo T con el id especificado en el parámetro ident que se encuentra en la colección.
    Como precondición el elemento de tipo T DEBERÁ existir y estar dentro de la colección, ya que la función
    recorre toda la colección, asumiendo que esto es así, hasta hallar el elemento.
*/
template<typename T>
T obtenerITF(const string &ident, const ColeccionITF<T> &c) {
    /*
    typename ColeccionITF<T>::Nodo* pAux = c.primero;

    bool encontrado = false;

    while(!encontrado) {

        if(identificador(pAux->dato) == ident) {

            encontrado = true;

        } else {

            pAux = pAux->sig;

        }

    }

    T itfObtenido = pAux->dato;

    return itfObtenido;
    */
    
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
    Para ello recorre toda la colección y agrega a un string, que comienza vacío (""), todos los IDs,
    de los elementos de tipo T que cumplen la condición nombrada anteriormente, separados por el parámetro separador.
*/
template<typename T>
string obsoletos(const Fecha &f, const string &separador, const ColeccionITF<T> &c) {
    /*
    string ids = "";

    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        while(pAux != nullptr) {

            if(anterior(fecha(pAux->dato), f)) {

                if(ids != "") {

                    ids += separador;

                }

                ids += identificador(pAux->dato);
            }
            
            pAux = pAux->sig;
        }

    }

    return ids;
    */

}
 

/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Elimina de c todos los ítems con fecha estrictamente anterior a f.
*/
template<typename T>
void purgar(const Fecha &f, ColeccionITF<T> &c) {
    //Recorrido COMPLETO ya que están ordenados por id, no fecha y hay que encontrar todos
    purgarPostOren<T>(f, c, c.raiz);
}


/*
    Función auxiliar recursiva de purgar. Recorre en postorden el abb raiz y borra aquellos nodos cuya fecha del dato sea anterior a fLim
*/
template<typename T>
void purgarPostOren(const Fecha &fLim, ColeccionITF<T> &c, typename ColeccionITF<T>::Nodo* &raiz){
    //postorden{   if(dato.fecha < fechaLim){ borrar(dato) }  }
    
    if(raiz != nullptr){    //CASO BASE - nodo vacío - parar
        // CASO RECURSIVO -- recorrido en POSTorden - 1)HijoIzq, 2)HijoDcho,  3)Raiz - RAIZ EL ÚLTIMO, por si hay que borrarla
        
        //HijoIzq
        purgarPostOren<T>(fLim, c, raiz->izq);
        //HijoDcho
        purgarPostOren<T>(fLim, c, raiz->der);
        //Raiz
        if( anterior(fecha(raiz->dato), fLim) ){ //si la fecha del nodo actual es anterior a la de Límite -> borrar
            bool borrado = false;
            borrarRec<T>( identificador(raiz->dato), raiz, borrado );   //borrarRec porque Borrar recorrería toda c otra vez y solo queremos borrar en raiz
            if(borrado){
                c.nElem--;
            }
        } 
    }
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve verdad si y sólo si en c hay algún ítem con tema igual a t.
*/
template<typename T>
bool existeTema(const string &t, const ColeccionITF<T> &c) {
    //Recorrido COMPLETO CON STOP ya que están ordenados por id, no tema, pero cuando lo encuentre no hay propósito en buscar más
    bool encontrado = false;
    existeTemaPreOren<T>(t, c.raiz, encontrado);
    return encontrado;
}


/*
    Funcion auxiliar recursiva de existeTema. Busca en preorden un solo item en el abb raiz con tema == t, si lo encuentra en el nodo de raiz,
    para de buscar y encontrado queda a verdadero. Si no lo encuentra, seguirá recorriendo el arbol. Si no lo ha encontrado en todo el
    árbol, encontrado se quedará a falso

    La raiz(puntero a nodo) no se pasa por referencia porque se tiene que llamar mediante c.raiz en existeTema, donde c es const.
    Al ser raiz un puntero, no es grave, ya que en vez de pasar un PUNTERO a puntero a Nodo(paso por referencia) pasa un PUNTERO a Nodo.
*/
template<typename T>
void existeTemaPreOren(const string &t, const typename ColeccionITF<T>::Nodo* raiz, bool &encontrado){   
    //preorden(mientras !encontrado){   encontrado = ( dato.tema == t )  }

    if( !(raiz == nullptr || encontrado) ){    //CASO BASE - nodo vacío O ya se ha encontrado - parar
        // CASO RECURSIVO -- recorrido en preOrden: 1)Raiz, 2)HijoIzq, 3)HijoDcho
        //Raiz
        encontrado = ( t == tema(raiz->dato) ); //si el tema del nodo es el que buscamos -> encontrado
        //HijoIzq
        existeTemaPreOren<T>(t, raiz->izq, encontrado);
        //HijoDcho
        existeTemaPreOren<T>(t, raiz->der, encontrado);
    }
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con tema igual a t, y separados entre sí por la cadena separador.
*/
template<typename T>
string delTema(const string &t, const string &separador, const ColeccionITF<T> &c) {
    /*
    string ids = "";

    // Si la coleccion está vacía se devuelve una cadena vacía directamente.
    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        while(pAux != nullptr) {

            if(tema(pAux->dato) == t) {

                if(ids != "") {

                    ids += separador;

                }

                ids += identificador(pAux->dato);

            }

            pAux = pAux->sig;

        }

    }

    return ids;
    */

}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t.
*/
template<typename T>
void zanjarTema(const string &t, ColeccionITF<T> &c) {
    /*
    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAnt = nullptr;
        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        typename ColeccionITF<T>::Nodo* pDeleter;

        while(pAux != nullptr) {

            if(tema(pAux->dato) == t) {

                if(pAux == c.primero) {

                    c.primero = c.primero->sig;

                } else {

                    pAnt->sig = pAux->sig;

                }

                pDeleter = pAux;
                pAux = pAux->sig;

                if(c.iter == pDeleter) {

                    c.iter = pAux;

                }

                delete(pDeleter);
                c.nElem--;

            } else {

                pAnt = pAux;
                pAux = pAux->sig;

            }

        }

    }
    */

}



/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve verdad si y sólo si c no contiene ningún ítem.
*/
template<typename T>
bool esVacia(const ColeccionITF<T> &c) {

    //return c.nElem == 0;

}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve el número de ítems que hay en la colección c.
*/
template<typename T>
int tamano(const ColeccionITF<T> &c) {

    //return c.nElem;

}



// --- FUNCIONES DEL ITERADOR ---


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
    ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
    haber visitado ningún ítem).
*/
template<typename T>
void iniciarIterador(ColeccionITF<T> &c){

    //c.iter = c.primero;
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c (si el iterador no está apuntando a NIL),
    devuelve falso si ya se ha visitado el último ítem.
*/
template<typename T>
bool existeSiguiente(const ColeccionITF<T> &c){

    //return (c.iter != nullptr);
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------
    Si existe un elemento por visitar en c devuelve TRUE, devuelve dicho elemento por e y avanza el iterador.
    Si no, devuelve falso.
*/
template<typename T>
bool siguienteYavanza(ColeccionITF<T> &c, T &e){
    /*
    if(existeSiguiente(c)){ //(si no apunta a NIL)

        e = c.iter->dato;
        c.iter = c.iter->sig;
        return true;

    }else{
        return false;
    }
    s*/
}


#endif //fin de coleccionITF.hpp