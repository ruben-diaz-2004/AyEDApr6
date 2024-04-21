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

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "arbolbinario.h"
#include "abequilibrado.h"
#include "abbusqueda.h"
#include "nif.h"
#include "nodob.h"

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

int main(int argc, char *argv[]) {
  parameters options = parse_args(argc, argv);

  // StaticSequence<Nif>* sequencia_a_ordenar;
  // switch (options.init_code) {
  //   case 0:
  //     sequencia_a_ordenar = new StaticSequence<Nif>(options.size, options.init_code); // Manual
  //     break;
  //   case 1:
  //     sequencia_a_ordenar = new StaticSequence<Nif>(options.size, options.init_code); // Random
  //     break;
  //   case 2:
  //     std::fstream file(options.file_name);
  //     sequencia_a_ordenar = new StaticSequence<Nif>(options.size, file); // File
  //     break;
  // }

  AB<Nif>* arbol;
  switch (options.tipo_de_arbol) {
    case 0:
      arbol = new ABE<Nif>();
      break;
    case 1:
      arbol = new ABB<Nif>();
      break;
  }

  switch (options.init_code) {
    case 0:
      // arbol->InicializarManual();
      break;
    case 1:
      // arbol->InicializarAleatorio(options.numero_de_elementos);
      break;
    case 2:
      // arbol->InicializarFichero(options.numero_de_elementos, options.file_name);
      break;
  }

  Nif* nif;
  long clave;
  int opcion;
  bool running = true;
  while (running) {
    std::cout << std::endl;
    ImprimeMenu();
    std::cin >> opcion;
    switch (opcion) {
      case 0:
        running = false;
        break;
      case 1:
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> clave;
        nif = new Nif(clave);
        arbol->Insertar(*nif);
        break;
      case 2:
        std::cout << "Introduce la clave a buscar: ";
        std::cin >> clave;
        nif = new Nif(clave);
        if (arbol->Buscar(*nif)) {
          std::cout << "Clave encontrada" << std::endl;
        } else {
          std::cout << "Clave no encontrada" << std::endl;
        }
        break;
      case 3:
        arbol->Inorden(arbol->raiz_);
        std::cout << std::endl;
        break;
    }
    std::cout << *arbol << std::endl;
  } 
  // SortMethod<Nif>* metodo_ordenacion;
  // switch (options.sort_code) {
  //   case 0:
  //     metodo_ordenacion = new SelectionSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
  //     break;
  //   case 1:
  //     metodo_ordenacion = new QuickSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
  //     break;
  //   case 2:
  //     metodo_ordenacion = new HeapSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
  //     break;
  //   case 3:
  //     metodo_ordenacion = new ShellSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
  //     break;
  //   case 4:
  //     metodo_ordenacion = new RadixSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
  //     break;
  // }

  // std::cout << "Antes de ordenar" << std::endl << std::endl;
  // metodo_ordenacion->Print();
  // std::cout << "Llamando al metodo de ordenacion" << std::endl;
  // metodo_ordenacion->Sort();
  // std::cout << "Despues de ordenar" << std::endl;
  // metodo_ordenacion->Print();

  // bool running = true;
  // char stop;
  // long clave;
  // while(running) {
  //   std::cin >> stop;
  //   switch(stop) {
  //     case 'x':
  //       running = false;
  //       break;
  //     default:
  //       running = false;
  //       break;
  //   }
  // }

  return 0;
}