// Copyright (C) 2013  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#undef DLIB_FFt_ABSTRACT_H__
#ifdef DLIB_FFt_ABSTRACT_H__

#include "matrix_abstract.h"
#include "../algs.h"

namespace dlib
{

// ----------------------------------------------------------------------------------------

    bool is_power_of_two (
        const unsigned long& value
    );
    /*!
        ensures
            - returns true if value contains a power of two and false otherwise.  As a
              special case, we also consider 0 to be a power of two.
    !*/

// ----------------------------------------------------------------------------------------

    template <
        typename T, 
        long NR, 
        long NC, 
        typename MM, 
        typename L
        >
    matrix<std::complex<T>,NR,NC,MM,L> fft (
        const matrix<std::complex<T>,NR,NC,MM,L>& data
    );
    /*!
        requires
            - is_vector(data) == true
            - is_power_of_two(data.size()) == true
        ensures
            - Computes the discrete Fourier transform of the given data vector and
              returns it.  In particular, we return a matrix D such that:
                - D.nr() == data.nr()
                - D.nc() == data.nc()
                - D(0) == the DC term of the Fourier transform.
                - starting with D(0), D contains progressively higher frequency components
                  of the input data.
                - ifft(D) == D
            - if DLIB_USE_FFTW is #defined then this function will use the very fast fftw
              library when given double precision matrices instead of dlib's default fft
              implementation.
    !*/

// ----------------------------------------------------------------------------------------

    template <
        typename T, 
        long NR, 
        long NC, 
        typename MM, 
        typename L
        >
    matrix<std::complex<T>,NR,NC,MM,L> ifft (
        const matrix<std::complex<T>,NR,NC,MM,L>& data 
    );
    /*!
        requires
            - is_vector(data) == true
            - is_power_of_two(data.size()) == true
        ensures
            - Computes the inverse discrete Fourier transform of the given data vector and
              returns it.  In particular, we return a matrix D such that:
                - D.nr() == data.nr()
                - D.nc() == data.nc()
                - fft(D) == data 
            - if DLIB_USE_FFTW is #defined then this function will use the very fast fftw
              library when given double precision matrices instead of dlib's default fft
              implementation.
    !*/

// ----------------------------------------------------------------------------------------

}

#endif // DLIB_FFt_ABSTRACT_H__

