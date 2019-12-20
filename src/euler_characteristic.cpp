#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  int max_index = 0;
  for( int i = 0; i < F.rows(); i++){
    for( int j = 0; j < F.cols(); j++){
       max_index = std::max(F(i,j), max_index);
    }
  }
  Eigen::MatrixXi edge = edges(F);
  Chi = max_index + 1 - edge.rows() + F.rows();
  return Chi;
}
