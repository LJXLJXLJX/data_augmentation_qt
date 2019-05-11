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
		m_dist_ptr(nullptr), m_rd(), m_gen(m_rd()), m_pdf(DIST_NORMAL) {}

	~DistributionWrapper() { delete m_dist_ptr; }

	void setNormalDistribution(double mu, double sigma);

	void setUniformDistribution(double a, double b);

	void setGammaDistribution(double alpha, double beta);

	int getValue();

private:
	void* m_dist_ptr;
	std::random_device m_rd;
	std::mt19937 m_gen;
	int m_pdf;
};