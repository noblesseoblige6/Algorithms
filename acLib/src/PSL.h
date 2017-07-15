#pragma once
#include <vector>

#include "Vec.h"
#include "Constant.h"

namespace acLib
{
    namespace psl
    {
        using namespace std;

        class PSL
        {
        public:
            PSL();
            ~PSL();
        };

        class ProbabilityDensity1D
        {
        public:
            ProbabilityDensity1D(const vector<double>& func);
            ~ProbabilityDensity1D();

            double SampleContinuous(const double val, double* pdf = NULL) const ;
            double SampleDiscrete(const double val, double* pdf = NULL) const ;

        protected:
            vector<double> m_func;
            vector<double> m_cumulativeDensity;

            double m_funcIntegrated;
        };
    }
}