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


#ifndef EQUILIBRADO_H
#define EQUILIBRADO_H

#include "arbolbinario.h"
#include "nodob.h"


template <class key>
class ABE: public AB<key> {
  public:
  ABE(): AB<key>() {}
  const bool Equilibrado() { return EquilibrioRama(this->raiz_); }
  const bool EquilibrioRama(NodoB<key>* nodo);
  void InsertaEquil(const key& dato);
  void InsertaEquilRama(const key& dato, NodoB<key>* nodo);
  bool Insertar(const key& k) { InsertaEquil(k); return true; }
  bool Buscar(const key& k) { return false; }
};



template <class key>
const bool ABE<key>::EquilibrioRama(NodoB<key>* nodo) {
  if (nodo == nullptr) return true;
  int equilibrio = TamRama(nodo->izdo_) - TamRama(nodo->dcho_);
  switch (equilibrio) {
    case -1:
    case 0:
    case 1:
      return EquilibrioRama(nodo->izdo_) && EquilibrioRama(nodo->dcho_);
    default:
      return false;
  }
}


template <class key>
void ABE<key>::InsertaEquil(const key& dato) {
  if (this->raiz_ == nullptr) {
    this->raiz_ = new NodoB<key>(dato, NULL, NULL);
    return;
  }
  InsertaEquilRama(dato, this->raiz_);
}


template <class key>
void ABE<key>::InsertaEquilRama(const key& dato, NodoB<key>* nodo) {
  if (this->TamRama(nodo->izdo_) <= this->TamRama(nodo->dcho_)) {
    if (nodo->izdo_ != NULL) {
      InsertaEquilRama(dato, nodo->izdo_);
    } else {
      nodo->izdo_ = new NodoB<key>(dato, NULL, NULL);
    }
  }
  else {
    if (nodo->dcho_ != NULL) {
      InsertaEquilRama(dato, nodo->dcho_);
    } else {
      nodo->dcho_ = new NodoB<key>(dato, NULL, NULL);
    }
  }
}
#endif