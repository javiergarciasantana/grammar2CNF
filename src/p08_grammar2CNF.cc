// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 8: Grammar2CNF
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 20/11/2022
//
// Archivo cya-P08-grammar2CNF: Programa cliente
//
// Historial de revisiones
// 20/11/2022 - Creacion (primera version) del codigo

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "grammar.h"
#include "usage.h"


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  
  std::ifstream gra_file;
  gra_file.open(argv[1], std::ios_base::in);
  std::ofstream output;
  output.open(argv[2], std::ios_base::out);
  

  if (gra_file.is_open() && output.is_open()) {
    Grammar gramatica(gra_file);
    output << gramatica.ChomskyChanger();
    
  } else {
    std::cerr << std::endl << "Error al abrir el fichero de entrada :(" << std::endl << std::endl;
    return 1;
  }
  return 0;
}