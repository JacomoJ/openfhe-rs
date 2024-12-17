#include "DiscreteGaussianSampler.h"

#include "openfhe/src/lib.rs.h"

namespace openfhe {
    // initializations
    BitGeneratorPtr::BitGeneratorPtr(std::shared_ptr<BitGenerator>&& bitGenerator) noexcept 
        : m_bitGenerator(std::move(bitGenerator))
    { }

    // GetRefs
    const std::shared_ptr<BitGenerator>& BitGeneratorPtr::GetRef() const noexcept {
        return m_bitGenerator;
    }

    // Generator functions
    std::unique_ptr<BitGenerator> GetBitGenerator() {
        return std::make_unique<BitGenerator>();
    }

    std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(
        const double center, 
        const double std, 
        BitGenerator* bitGenerator, 
        const BaseSamplerType type) 
    {
        return std::make_unique<BaseSampler>(center, std, bitGenerator, type);
    }
    
    std::unique_ptr<DiscreteGaussianGeneratorImpl> GetGeneratorWithParams(const double std) {
        return std::make_unique<DiscreteGaussianGeneratorImpl>(std);
    }

    std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGeneratorGenericWithParams(
        BaseSampler** samplers, 
        const double std, 
        const int64_t b, 
        const double N) 
    {
        return std::make_unique<DiscreteGaussianGeneratorGeneric>(samplers, std, b, N);
    }
}
