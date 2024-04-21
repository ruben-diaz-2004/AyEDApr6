/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 13/04/2024
  * @brief árbol binario de búsqueda
  */


#ifndef BUSQUEDA_H
#define BUSQUEDA_H


#include "arbolbinario.h"
#include "nodob.h"

template <class key>
class ABB: public AB<key> {
  public:
  bool Buscar(const key& clave) { return BuscarRama(this->raiz_, clave) != NULL; }
  NodoB<key>* BuscarRama(NodoB<key>* nodo, const key& clave);
  bool Insertar(const key& clave) { InsertarRama(this->raiz_, clave); return true; }
  void InsertarRama(NodoB<key>* &nodo, const key& clave);
};


template <class key>
NodoB<key>* ABB<key>::BuscarRama(NodoB<key>* nodo, const key& clave) {
  if (nodo == NULL) return NULL;
  if (clave == nodo->dato_) return nodo;
  if (clave < nodo->dato_) return BuscarRama(nodo->izdo_, clave);
  return BuscarRama(nodo->dcho_, clave);
}


template <class key>
void ABB<key>::InsertarRama(NodoB<key>* &nodo, const key& clave) {
  if (nodo == NULL) {
    nodo = new NodoB<key>(clave);
  } else if (clave < nodo->dato_) {
      InsertarRama(nodo->izdo_, clave);
  }
  else InsertarRama(nodo->dcho_, clave);
}

#endif