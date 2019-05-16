#include "distribution_wrapper.h"
#include <algorithm>

using namespace std;


void DistributionWrapper::setNormalDistribution(double mu, double sigma)
{
	m_pdf = DIST_NORMAL;
	m_normal_dist.param(normal_distribution<>::param_type(mu, sigma));
}

void DistributionWrapper::setUniformDistribution(double a, double b)
{
	m_pdf = DIST_UNIFORM;
	m_uniform_real_dist.param(uniform_real_distribution<>::param_type(a, b));
}

void DistributionWrapper::setGammaDistribution(double alpha, double beta)
{
	m_pdf = DIST_GAMMA;
	m_gamma_dist.param(gamma_distribution<>::param_type(alpha, beta));
}

double DistributionWrapper::getValue()
{
	double ret = 0;
	if (m_pdf == DIST_NORMAL) {
		ret = m_normal_dist(m_gen);
	}
	else if (m_pdf == DIST_UNIFORM) {
		ret = m_uniform_real_dist(m_gen);
	}
	else if (m_pdf == DIST_GAMMA) {
		ret = m_gamma_dist(m_gen);
	}
	return ret;
}