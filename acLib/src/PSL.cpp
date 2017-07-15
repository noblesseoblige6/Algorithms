#include "PSL.h"

#include <algorithm>
#include <iterator>

#include "Utility.h"

namespace acLib
{
    namespace psl
    {
        using namespace acLib::utility;

        PSL::PSL()
        {
        }


        PSL::~PSL()
        {
        }

        // ProbabilityDensity1D Class
        ProbabilityDensity1D::ProbabilityDensity1D(const vector<double>& func)
        {
            copy(func.begin(), func.end(), back_inserter(m_func));

            const int size = m_func.size();

            m_cumulativeDensity.resize(size);

            // find cdf
            m_cumulativeDensity[0] = m_func[0];
            for (int i = 1; i < size; ++i)
            {
                m_cumulativeDensity[i] = m_cumulativeDensity[i - 1] + m_func[i];
            }

            // normalize
            for (int i = 0; i < size; ++i)
            {
                m_cumulativeDensity[i] /= m_cumulativeDensity.back();
            }

            // integrate func
            m_funcIntegrated = 0.0;
            const double delta = 1.0 / size;
            for (int i = 1; i < size; ++i)
            {
                m_funcIntegrated += m_func[i] * delta;
            }
        }

        ProbabilityDensity1D::~ProbabilityDensity1D()
        {}

        double ProbabilityDensity1D::SampleContinuous(const double val, double* pdf) const
        {
            vector<double>::const_iterator itr = lower_bound(m_cumulativeDensity.begin(),
                m_cumulativeDensity.end(),
                val);

            const int offset = max(0, (int)(itr - m_cumulativeDensity.begin())-1);

            double du = MathUtility::Lerp(val, m_cumulativeDensity[offset], m_cumulativeDensity[offset + 1]);

            if (pdf)
            {
                *pdf = m_func[offset] / m_funcIntegrated;
            }

            return  (offset + du) / m_func.size();
        }

        double ProbabilityDensity1D::SampleDiscrete(const double val, double* pdf) const
        {
            vector<double>::const_iterator itr = lower_bound(m_cumulativeDensity.begin(),
                m_cumulativeDensity.end(),
                val);

            const int offset = max(0, itr - m_cumulativeDensity.begin());

            double du = MathUtility::Lerp(val, m_cumulativeDensity[offset], m_cumulativeDensity[offset + 1]);

            if (pdf)
            {
                *pdf = m_func[offset] / (m_funcIntegrated * m_func.size());
            }

            return  offset;
        }
    }
}