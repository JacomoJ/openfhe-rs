#include "DiscreteGaussianSampler.h"

#include "openfhe/core/math/discretegaussiangenerator-impl.h"

#include "openfhe/src/lib.rs.h"

namespace openfhe {
    // initializations
    BitGeneratorPtr::BitGeneratorPtr(std::shared_ptr<BitGenerator>&& bitGenerator) noexcept 
        : m_bitGenerator(std::move(bitGenerator))
    { }

    BaseSamplerPtr::BaseSamplerPtr(std::shared_ptr<BaseSampler>&& baseSampler) noexcept 
        : m_baseSampler(std::move(baseSampler))
    { }

    DiscreteGaussianGeneratorPtr::DiscreteGaussianGeneratorPtr(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianSampler) noexcept 
        : m_discreteGaussianGeneratorGeneric(std::move(discreteGaussianSampler))
    { }

    // GetRefs
    const std::shared_ptr<BitGenerator>& BitGeneratorPtr::GetRef() const noexcept {
        return m_bitGenerator;
    }

    int64_t DiscreteGaussianGeneratorPtr::GenerateInteger(const double center, const double std) const {
        return m_discreteGaussianGeneratorGeneric -> GenerateInteger(center, std);
    }

    // Generator functions
    std::unique_ptr<BitGeneratorPtr> GetBitGenerator() {
        return std::make_unique<BitGeneratorPtr>();
    }

    std::unique_ptr<BaseSamplerPtr> GetBaseSampler() {
        return std::make_unique<BaseSamplerPtr>();
    }

    // std::unique_ptr<BaseSamplerPtr> GetBaseSamplerWithParams(const double center, const double std, const BitGeneratorPtr& bitGenerator, const BaseSamplerType bst) {
    //     return std::make_unique<BaseSamplerPtr>(center, std, bitGenerator, bst);h
    // }

    // std::unique_ptr<DiscreteGaussianGeneratorPtr> GetGeneratorWithParams(const* BaseSampler samplers, const double std, const uint32_t b, const double N) {
    //     return std::make_unique<DiscreteGaussianGeneratorPtr>(samplers, std, b, N);
    // }

    std::unique_ptr<DiscreteGaussianGeneratorPtr> GetGaussianGenerator() {
        return std::make_unique<DiscreteGaussianGeneratorPtr>();
    }
}
