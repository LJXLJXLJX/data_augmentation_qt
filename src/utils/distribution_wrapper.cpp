#include "distribution_wrapper.h"
#include <algorithm>

using namespace std;

void DistributionWrapper::setNormalDistribution(double mu, double sigma)
{
	if (m_dist_ptr != nullptr)
		delete m_dist_ptr;
	m_dist_ptr = new uniform_real_distribution<>(mu, sigma);
	m_pdf = DIST_NORMAL;
}

void DistributionWrapper::setUniformDistribution(double a, double b)
{
	if (m_dist_ptr != nullptr)
		delete m_dist_ptr;
	m_dist_ptr = new uniform_real_distribution<>(a, b);
	m_pdf = DIST_UNIFORM;
}

void DistributionWrapper::setGammaDistribution(double alpha, double beta)
{
	if (m_dist_ptr != nullptr)
		delete m_dist_ptr;
	m_dist_ptr = new gamma_distribution<>(alpha, beta);
	m_pdf = DIST_GAMMA;
}

int DistributionWrapper::getValue()
{
	double tmp = 0;
	if (m_pdf == DIST_NORMAL) {
		tmp = (*static_cast<normal_distribution<>*>(m_dist_ptr))(m_gen);
	}
	else if (m_pdf == DIST_UNIFORM) {
		tmp = (*static_cast<uniform_real_distribution<>*>(m_dist_ptr))(m_gen);
	}
	else if (m_pdf == DIST_GAMMA) {

	}
	tmp = round(tmp);
	int ret = tmp;
	return ret;
}
