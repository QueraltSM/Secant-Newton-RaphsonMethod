#include "iostream"
#include "string"
#include <math.h>
#include <conio.h>

using namespace std;

// Secant Method

int secantMethod () {

  real f_root_0 = (*f)(root_0); 
  real f_root_1 = (*f)(root_1); 

  for(int i = 0; i<Nmax; i++) {   
    if(f_root_1==0.) {return(i)}; 


    real h = root_1 - root_0; 
    if (h==0.) return(-1); 

    real derivada = (f_root_1 - f_root_0)/h; 
    if(derivada==0.) return(-2); 

    real root_2 = root_1 - f_root_1/derivada; 
    f_root_0 = f_root_1; 
    f_root_1 = (*f)(root_2);

  if (mn_distancia(root_1,root_2)<TOL) {
    root_0 = root_1; 
    root_1 = root_2; 
    return(i);

  }
    root_0 = root_1;
    root_1 = root_2;


  }
  
  return(-3);

}



// Newton - Raphson Methods


int NewtonRaphsonWithDerivative() {

  real f_root = (*f)(root);

  for (int i = 0; i<Nmax; i++) {
    if(f_root==0.) { return(i);}

    real derivada = (*f_1)(root);
    if (derivada==0.) return(-1);


    real root2 = root - f_root/derivada;
    f_root = (*f)(root2);


    if (mn_distancia(root2,root)<TOL) {
      root = root2;
      return(i);
  }
  
    root = root2;
    
  }
    
    return(-2);
}


int NewtonRaphsonWithoutDerivative() {

  real f_root = (*f)(root);

  for (int i = 0; i<Nmax; i++) {

    if(f_root==0.) {return(i)}

    real derivada = ((*f)(root+h) - f_root)/h;
    if (derivada==0.) return(-1);

    real root2 = root - f_root/derivada;
    f_root = (*f)(root2);



if (mn_distancia(root2,root)<TOL) {
    root=root2;
    return(i);
  }


    root = root2;
  }
    return(-2); 

}


int main () {}

