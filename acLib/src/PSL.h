#pragma once
#include <vector>

#include "Vec.h"
#include "Constant.h"

namespace acLib
{
    namespace psl
    {
        using namespace std;
        using namespace vec;

        class PSL
        {
        public:
            PSL();
            ~PSL();
        };

        class ProbabilityDensity1D
        {
        public:
            ProbabilityDensity1D() {}
            ProbabilityDensity1D(const vector<double>& func);
            ~ProbabilityDensity1D();

            double SampleContinuous(const double val, double* pdf = NULL) const ;
            double SampleDiscrete(const double val, double* pdf = NULL) const ;

            int GetFuncSize() const { return m_func.size(); }
            double GetFunc(const int index) { return m_func[index]; }
            double GetCumulativeDensity(const int index) {return m_cumulativeDensity[index];}
            double GetFuncIntegrated() const { return m_funcIntegrated; }

        protected:
            vector<double> m_func;
            vector<double> m_cumulativeDensity;

            double m_funcIntegrated;
        };

        class ProbabilityDensity2D
        {
        public:
            ProbabilityDensity2D() {}
            ProbabilityDensity2D(const vector<vector<double>>& func);
            ~ProbabilityDensity2D();

            Vec2 SampleContinuous(const Vec2& val, double* pdf = NULL) const;

        protected:
            vector<ProbabilityDensity1D> m_conditinalDensity;
            ProbabilityDensity1D m_marginalDensity;
        };
    }
}