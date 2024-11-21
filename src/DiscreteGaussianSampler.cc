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

    int32_t GenerateInt() const {
        m_discreteGaussianGenerator -> GenerateInt();
    }

    // std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const {
    //     m_discreteGaussianGenerator -> GenerateIntVector(size);
    // }

    // int32_t GenerateInteger() const {
    //     m_discreteGaussianGenerator -> GenerateInteger();
    // }
}