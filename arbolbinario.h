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


#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include "nodob.h"

template <class key>
class AB {
  public:
  bool Insertar(const key& k) = 0;
  bool Buscar(const key& k) = 0;
  void Inorden() const;
  friend std::ostream& operator<<(std::ostream& os, const AB<key>& arbol);

  private:
  NodoB<key>* raiz_;
};



#endif