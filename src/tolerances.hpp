/// Copyright (C) Luca Crippa <luca7.crippa@mail.polimi.it>
/// Copyright (C) Giacomo De Carlo <giacomo.decarlo@mail.polimi.it>
/// Under MIT license

#ifndef LOCALLY_STATIONARY_MODELS_TOLERANCES
#define LOCALLY_STATIONARY_MODELS_TOLERANCES

namespace LocallyStationaryModels
{
struct Tolerances
{
    /// value of the noise to be added to the anchor points grid to prevent out of domain points
    static constexpr double anchor_tolerance = 1e-6;
    /// default value of pi
    inline static double pi = 4*std::atan(1.);
    /// minimum threshold below which the determinant of a matrix is considered to be 0  
    static constexpr double min_determinant = 1e-12;
    /// optimization termination condition parameter epsilon
    static constexpr double param_epsilon = 1e-6;
    /// optimization termination condition parameter max_iterations
    static constexpr double param_max_iterations = 1000000;
    /// minimun threshold below which the norm of a vector is considered to be 0
    static constexpr double min_norm = 1e-12;
    /// huge value to be considered as infinite when returning inf would cause troubles
    static constexpr double infinity = 1e12;
}; // struct Tolerances
} // namespace LocallyStationaryModels

#endif //LOCALLY_STATIONARY_MODELS_TOLERANCES
