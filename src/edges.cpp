#include "edges.h"
#include <iostream>
#include <algorithm> 
#define MAX_VERTICES 10000

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  E.resize(MAX_VERTICES/2, 2);
  bool **tag = new bool*[MAX_VERTICES];
  for( int i = 0; i < MAX_VERTICES; i++){
    tag[i] = new bool[MAX_VERTICES];
    for( int j = 0; j < MAX_VERTICES; j++){
      tag[i][j] = false;
    }
  }

  int size = 0;
  for( int i = 0; i < F.rows(); i++){
    for( int j = 0; j < F.cols() - 1; j++){
      for( int k = j+1; k < F.cols(); k++){
        if(!tag[F(i,j)][F(i,k)]){
          E(size, 0) = std::min(F(i,j), F(i,k));
          E(size, 1) = std::max(F(i,j), F(i,k));
          tag[F(i,j)][F(i,k)] = true;
          tag[F(i,k)][F(i,j)] = true;
          size++;
          if(size >= E.rows()){
            E.conservativeResize(2*E.rows(), 2);
          }
        }
      }  
    }
  }
  E.conservativeResize(size, 2);

  for( int i = 0; i < MAX_VERTICES; i++){
    delete[] tag[i];
  }
  delete[] tag;
  return E;
}
