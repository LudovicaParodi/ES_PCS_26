#include <iostream>
#include "Eigen/Eigen"
#include "metodo_gradiente_coniugato.hpp"

int main() 
{
  const double tol = 1.0e-15;
  unsigned int n = 3;

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n); 

  if (abs(B.determinant()) < tol)
    return -1;

  Eigen::MatrixXd A = B.transpose() * B; //sono sicura di ottenere una matrice simmetrica semidef pos

  std::cout.precision(2);
  std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

  double res_norm_finale;
  double res_norm_0;
  const double res_tol = 1.0e-12;

  Eigen::VectorXd x = metodo_gradiente_coniugato(A, n, res_norm_finale, res_norm_0);

  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);    //soluzione esatta
  double errore = (x - x_ex).norm() / x_ex.norm();

  std::cout.precision(4);
  std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< std::endl;
  std::cout<< std::scientific<< res_norm_finale / res_norm_0<< "/"<< res_tol<< std::endl;   //misura relativa della riduzione del residuo
  std::cout<< std::scientific<< "soluzione"<< std::endl;
  std::cout<< std::scientific<< x << std::endl;
  std::cout << "errore relativo: " << std::scientific << errore << std::endl;

  return 0;
}