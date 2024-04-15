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

#include <iostream>
#include "usage.h"

void Usage(int argc, char* argv[]) {
    
  if (argc != 3) {  
    if (argc == 2) {
      std::string ayuda = "--help";
      if (ayuda == argv[1]) {
        std::cerr << "Modo de empleo: ./p08_grammar2CNF input.gra output.gra" <<std:: endl
            << std::endl << "Reportar fallos a: alu0101391663@ull.edu.es" << std::endl;
        exit(EXIT_SUCCESS);
      } else {
        std::cerr << "Número erroneo de parámetros..." << std::endl
           << "Modo de empleo: ./p08_grammar2CNF input.gra output.gra" << std::endl
           << "Pruebe ‘./p08_grammar2CNF --help’ para más información." << std::endl;
        exit(EXIT_SUCCESS);
      }
    } else {
      std::cerr << "Número erroneo de parámetros..." << std::endl
           << "Modo de empleo: ./p08_grammar2CNF input.gra output.gra" << std::endl
           << "Pruebe ‘./p08_grammar2CNF --help’ para más información." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}