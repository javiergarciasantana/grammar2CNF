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

#include <string>

#include "chain.h"
#include "symbol.h"
#include "alphabet.h"

#ifndef GRAMMAR_H
#define GRAMMAR_H

class Grammar {
 public:
  Grammar(std::ifstream& input);
  Grammar ChomskyChanger(void);

  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);

 private:
  Alphabet terminal_symbols_;
  Alphabet non_terminal_symbols_;
  Symbol starting_symbol_;
  std::string terminal_characters_;
  std::vector<std::pair<Symbol, Chain>> productions_;//vector de pares
};

#endif