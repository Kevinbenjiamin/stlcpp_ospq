# include <iostream>        // standard input/output
# include <vector>          // standard vector
# include <cppad/cppad.hpp> // the CppAD package

namespace { // begin the empty namespace
    // define the function Poly(a, x) = a[0] + a[1]*x[1] + ... + a[k-1]*x[k-1]
    template <class Type>
    Type Poly(const CPPAD_TESTVECTOR(double) &a, const Type &x)
    {   size_t k  = a.size();
        Type y   = 0.;  // initialize summation
        Type x_i = 1.;  // initialize x^i
        for(size_t i = 0; i < k; i++)
        {   y   += a[i] * x_i;  // y   = y + a_i * x^i
            x_i *= x;           // x_i = x_i * x
        }
        return y;
    }
}
// main program
int main(void)
{   using CppAD::AD;   // use AD as abbreviation for CppAD::AD
    using std::vector; // use vector as abbreviation for std::vector

    // vector of polynomial coefficients
    size_t k = 5;                  // number of polynomial coefficients
    CPPAD_TESTVECTOR(double) a(k); // vector of polynomial coefficients
    for(size_t i = 0; i < k; i++)
        a[i] = 1.;                 // value of polynomial coefficients

    // domain space vector
    size_t n = 1;               // number of domain space variables
    vector< AD<double> > ax(n); // vector of domain space variables
    ax[0] = 3.;                 // value at which function is recorded

    // declare independent variables and start recording operation sequence
    CppAD::Independent(ax);

    // range space vector
    size_t m = 1;               // number of ranges space variables
    vector< AD<double> > ay(m); // vector of ranges space variables
    ay[0] = Poly(a, ax[0]);     // record operations that compute ay[0]

    // store operation sequence in f: X -> Y and stop recording
    CppAD::ADFun<double> f(ax, ay);

    // compute derivative using operation sequence stored in f
    vector<double> jac(m * n); // Jacobian of f (m by n matrix)
    vector<double> x(n);       // domain space vector
    x[0] = 3.;                 // argument value for computing derivative
    jac  = f.Jacobian(x);      // Jacobian for operation sequence

    // print the results
    std::cout << "f'(3) computed by CppAD = " << jac[0] << std::endl;

    // check if the derivative is correct
    int error_code;
    if( jac[0] == 142. )
        error_code = 0;      // return code for correct case
    else  error_code = 1;    // return code for incorrect case

    return error_code;
}

