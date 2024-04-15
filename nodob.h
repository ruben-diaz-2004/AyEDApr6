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


template <class key>
class NodoB {

  protected:
    key dato_;
    NodoB<key>* izdo_;
    NodoB<key>* dcho_;
};


#endif