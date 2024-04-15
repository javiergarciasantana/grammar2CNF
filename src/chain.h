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
#include <string>
#include <vector>
#include <set>

#include "alphabet.h"

#ifndef CHAIN_H
#define CHAIN_H

class Chain {
 public:
  Chain();    //Constructor por defecto(cadena vacia)
  Chain(std::string workload);  //Constructor por parametro
  //Getters
  Alphabet getAlphabet() const { return alphabet_; }
  std::vector<Symbol> getChain() const { return chain_; }
  //Sobrecarga del operador de extraccion
  friend std::ostream& operator<<(std::ostream& out, const Chain& desired_chain);
  bool operator==(const Chain& other_chain) const;
  bool operator!=(const Chain& other_chain) const;
  bool operator<(const Chain& other_chain) const;
  Chain operator+(const Chain& chain) const;

 private:
  std::vector<Symbol> workload_;
  Alphabet alphabet_;
  std::vector<Symbol> chain_;
  std::vector<Symbol> empty_chain_;
};


#endif  //CHAIN_H