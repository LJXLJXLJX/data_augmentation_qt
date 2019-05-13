#pragma once
#include <random>


enum PDF {
	DIST_GAUSSIAN,
	DIST_NORMAL,
	DIST_UNIFORM,
	DIST_GAMMA
};




class DistributionWrapper {
public:
	DistributionWrapper() :
		m_rd(), m_gen(m_rd()), m_pdf(DIST_NORMAL) {}

	~DistributionWrapper() {}

	void setNormalDistribution(double mu, double sigma);

	void setUniformDistribution(double a, double b);

	void setGammaDistribution(double alpha, double beta);

	int getValue();

private:

	std::random_device m_rd;
	std::mt19937 m_gen;
	std::normal_distribution<> m_normal_dist;
	std::uniform_real_distribution<> m_uniform_real_dist;
	std::gamma_distribution<> m_gamma_dist;

	int m_pdf;
};