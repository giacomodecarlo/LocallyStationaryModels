/// Copyright (C) Luca Crippa <luca7.crippa@mail.polimi.it>
/// Copyright (C) Giacomo De Carlo <giacomo.decarlo@mail.polimi.it>
/// Under MIT license

#ifndef LOCALLY_STATIONARY_MODELS_SMOOTH
#define LOCALLY_STATIONARY_MODELS_SMOOTH

#include "kernel.hpp"
#include "traits.hpp"

namespace LocallyStationaryModels
{
/**
 * \brief a class to perform kernel smoothing of the paramters estimated in the anchor points to get the non stationary value of the parameters in any position of the domain
*/
class Smt
{
private:
    cd::matrixptr m_solutions = nullptr; /// matrix wiht the solution of the optimization
    cd::matrixptr m_anchorpos = nullptr; /// anchor points

    Kernel m_kernel; /// kernel

    double m_optimal_delta = 0; /// optimal value for delta

    /**
     * \brief       smooth a single parameter for a point in position pos
     * \param pos   a vector of coordinates or the index of the position of the point where to find the smoothed value of the parameter
     * \param n     the index of the parameter to obtain
    */
    double smooth_value(const unsigned int &pos, const unsigned int &n) const;
    double smooth_value(const cd::vector &pos, const unsigned int &n) const;

public:
    /**
     * \brief constructor
     * \param solutions     a shared pointer to the solutions of the optimization
     * \param anchorpos     a vector containing the indeces of the anchor position obtained by clustering
     * \param d             a shared pointer to the matrix of the coordinates
     * \param min_delta     the minimum exponent for the cross-validation of the delta bandwidth parameter for gaussian kernel smoothing
     * \param max_delta     the maximum exponent for the cross-validation of the delta bandwidth parameter for gaussian kernel smoothing
    */
    Smt(const cd::matrixptr solutions_, const cd::matrixptr &anchorpos_, const cd::scalar &min_delta, const cd::scalar &max_delta, const std::string &kernel_id);
    /**
     * \brief constructor
     * \param solutions     a shared pointer to the solutions of the optimization
     * \param anchorpos     a vector containing the indeces of the anchor position obtained by clustering
     * \param d             a shared pointer to the matrix of the coordinates
     * \param delta         a user-chosen value for delta
    */
    Smt(const cd::matrixptr solutions, const cd::matrixptr &anchorpos, const double delta, const std::string &kernel_id);
    /**
     * \brief call the default constructor for kernel_
    */
    Smt();

    /**
     * \brief       smooth all the parameters for a point in position pos
     * \param pos   a vector of coordinates or the index of the position of the point where to find the smoothed value of the parameters
    */
    template<class Input>
    cd::vector smooth_vector(const Input &pos) const
    {
        cd::vector result(m_solutions->cols());
        for (unsigned int i=0; i<m_solutions->cols(); ++i)
            result(i) = smooth_value(pos, i);

        return result;
    };

    /**
     * \brief   return a shared pointer to the solutions found by the optimizer
    */
    const cd::matrixptr get_solutions() const;
    /**
     * \brief   return the delta found by cross-validation evaluated on sigma, the same delta is used for all the parameters
    */
    double get_optimal_delta() const;
    /**
     * \brief   return a shared pointer the coordinates of the anchorpoints
    */
    const cd::matrixptr get_anchorpos() const;
}; // class Smt
} // namespace LocallyStationaryModels

#endif //LOCALLY_STATIONARY_MODELS_SMOOTH
