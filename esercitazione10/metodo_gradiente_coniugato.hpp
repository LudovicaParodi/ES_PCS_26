#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

Eigen::VectorXd metodo_gradiente_coniugato(const Eigen::MatrixXd& A, int n, double& res_norm_finale, double& res_norm_0) {

  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //è la soluzione esatta
  Eigen::VectorXd b = A * x_ex;

  const double res_tol = 1.0e-12;

  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd res = b - A * x;
  Eigen::VectorXd p = res; //p0=r0
  res_norm_0 = res.norm();

  while (res.norm() > res_tol * res_norm_0)
  {
    const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();
    x = x + alpha_k * p;

    Eigen::VectorXd res_new = b - A*x;

    const double beta_k = ((p.transpose() * A * res_new) / (p.transpose() * A * p)).value();  
    p = res_new - beta_k * p;

    res = res_new;
  }

  res_norm_finale = res.norm();
  return x;
};
