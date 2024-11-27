#include "DiscreteGaussianSampler.h"

#include "openfhe/core/math/discretegaussiangenerator-impl.h"

#include "openfhe/src/lib.rs.h"

namespace openfhe {
    DiscreteGaussianSampler::DiscreteGaussianSampler(std::shared_ptr<DiscreteGaussianGeneratorImpl>&&    discreteGaussianSampler) noexcept 
        : m_discreteGaussianGenerator(std::move(discreteGaussianSampler))
    { }

    void DiscreteGaussianSampler::Initialize() const {
        m_discreteGaussianGenerator -> Initialize();
    }

    int32_t DiscreteGaussianSampler::GenerateInt() const {
        return m_discreteGaussianGenerator -> GenerateInt();
    }

    // std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const {
    //     m_discreteGaussianGenerator -> GenerateIntVector(size);
    // }

    // Generator function
    std::unique_ptr<DiscreteGaussianSampler> GetSampler() {
        return std::make_unique<DiscreteGaussianSampler>();
    }

    // int32_t GenerateInteger() const {
    //     m_discreteGaussianGenerator -> GenerateInteger();
    // }
}