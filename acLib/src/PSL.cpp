namespace acLib
{
    namespace psl
    {
        using namespace util;
        using namespace vec;

        PSL::PSL()
        {
        }


        PSL::~PSL()
        {
        }

        double PSL::PDFSolidAngleToArea(const double pdf, const Vec3& nowPoint, const Vec3& nextPoint, const Vec3& nextNormal)
        {
            const Vec3 vector = nowPoint - nextPoint;
            return pdf * std::max( Vec3::dot( Vec3::normalize(vector), nextNormal), 0.0) / vector.normSq();
        }

        double PSL::PDFAreaToSolidAngle(const double pdf, const Vec3& nowPoint, const Vec3& nextPoint, const Vec3& nextNormal)
        {
            const Vec3 vector = nowPoint - nextPoint;
            return pdf * vector.normSq() / std::max( Vec3::dot( Vec3::normalize(vector), nextNormal), 0.0);
        }


        // ProbabilityDensity1D Class
        ProbabilityDensity1D::ProbabilityDensity1D(const vector<double>& func)
        {
            copy(func.begin(), func.end(), back_inserter(m_func));

            const int size = (int)m_func.size();

            m_cumulativeDensity.resize(size);

            // find cdf
            m_cumulativeDensity[0] = m_func[0];
            for (int i = 1; i < size; ++i)
            {
                m_cumulativeDensity[i] = m_cumulativeDensity[i - 1] + m_func[i];
            }

            // integrate func
            m_funcIntegrated = 0.0;
            const double delta = 1.0 / size;
            for (int i = 1; i < size; ++i)
            {
                m_funcIntegrated += m_func[i] * delta;
            }

            // normalize
            for (int i = 0; i < size; ++i)
            {
                m_cumulativeDensity[i] /= m_cumulativeDensity.back();
            }
        }

        ProbabilityDensity1D::~ProbabilityDensity1D()
        {}

        double ProbabilityDensity1D::SampleContinuous(const double val, double* pdf) const
        {
            vector<double>::const_iterator itr = lower_bound(m_cumulativeDensity.begin(),
                m_cumulativeDensity.end(),
                val);

            const int offset = max(0, (int)(itr - m_cumulativeDensity.begin()) - 1);

            double du = MathUtil::Lerp(val, m_cumulativeDensity[offset], m_cumulativeDensity[offset + 1]);

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

            const int offset = max(0, (int)(itr - m_cumulativeDensity.begin()));

            double du = MathUtil::Lerp(val, m_cumulativeDensity[offset], m_cumulativeDensity[offset + 1]);

            if (pdf)
            {
                *pdf = m_func[offset] / (m_funcIntegrated * m_func.size());
            }

            return  offset;
        }

        // ProbabilityDensity2D Class
        ProbabilityDensity2D::ProbabilityDensity2D(const vector<vector<double>>& func)
        {
            const int numU = (int)func.size();
            const int numV = (int)func[0].size();

            m_conditinalDensity.resize(numV);
            for (int v = 0; v < numV; ++v)
            {
                vector<double> tmp(numU);
                for (int u = 0; u < numU; ++u)
                {
                    tmp[u] = func[u][v];
                }

                m_conditinalDensity[v] = ProbabilityDensity1D(tmp);
            }

            vector<double> marginalFunc(numV, 0.0);
            for (int v = 0; v < numV; ++v)
            {
                #if 0
                marginalFunc[v] = m_conditinalDensity[v].GetFuncIntegrated();
                #else
                for (int u = 0; u < numU; ++u)
                {
                    marginalFunc[v] += m_conditinalDensity[v].GetFunc(u);
                }
                marginalFunc[v] /= numU;
                #endif
            }
            m_marginalDensity = ProbabilityDensity1D(marginalFunc);
        }

        ProbabilityDensity2D::~ProbabilityDensity2D()
        {}

        Vec2 ProbabilityDensity2D::SampleContinuous(const Vec2& val, double* pdf) const
        {
            Vec2 uv;
            double uPdf, vPdf;

            uv.y = m_marginalDensity.SampleContinuous(val.y, &vPdf);

            const int v = (int)MathUtil::Clamp((int)(uv.y * m_marginalDensity.GetFuncSize()), 0, m_marginalDensity.GetFuncSize() - 1);
            uv.x = m_conditinalDensity[v].SampleContinuous(val.x, &uPdf);

            //@comment each probability is independent
            *pdf = uPdf * vPdf;

            return uv;
        }

        // @comment find conditional probability density
        double ProbabilityDensity2D::FindConditinalPdf(const Vec2& uv) const
        {
            const int x = MathUtil::Clamp((int)(uv.x * m_conditinalDensity[0].GetFuncSize()), 0, m_conditinalDensity[0].GetFuncSize() - 1);
            const int y = MathUtil::Clamp((int)(uv.y * m_marginalDensity.GetFuncSize()), 0, m_marginalDensity.GetFuncSize()-1);

            #if 0
            const double denominator = m_conditinalDensity[y].GetFuncIntegrated() * m_marginalDensity.GetFuncIntegrated();
            if (denominator == 0.0)
            {
                return 0.0;
            }

            return (m_conditinalDensity[y].GetFunc(x) * m_marginalDensity.GetFunc(y)) / denominator;
            #else
             const double denominator = m_conditinalDensity[y].GetFuncIntegrated();
            if (denominator == 0.0)
            {
                return 0.0;
            }

            return m_marginalDensity.GetFuncIntegrated() / denominator;
            #endif
        }
    }
}