#include "DiscreteGaussianSampler.h"

#include "openfhe/core/math/discretegaussiangenerator-impl.h"

#include "openfhe/src/lib.rs.h"

namespace openfhe {
    // initializations
    BitGenerator::BitGenerator(std::shared_ptr<BitGenerator>&& bitGenerator) noexcept 
        : m_bitGenerator(std::move(bitGenerator))
    {}

    BaseSampler::BaseSampler(std::shared_ptr<BaseSampler>&& baseSampler) noexcept {
    }

    DiscreteGaussianSampler::DiscreteGaussianSampler(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianSampler) noexcept 
        : m_discreteGaussianGeneratorGeneric(std::move(discreteGaussianSampler))
    { }

    // GetRefs
    const std::shared_ptr<BitGenerator>& BitGenerator::GetRef() const noexcept {
        return m_bitGenerator;
    }

    const std::shared_ptr<BaseSampler>& BaseSampler::GetRef() const noexcept {
        return m_baseSampler;
    }

    const std::shared_ptr<DiscreteGaussianGeneratorImpl>& DiscreteGaussianSampler::GetRef() const noexcept {
        return m_discreteGaussianGenerator;
    }

    // void DiscreteGaussianSampler::Initialize() const {
    //     m_discreteGaussianGenerator -> Initialize();
    // }

    // void DiscreteGaussianSampler::SetStd(const double std) {
    //     m_discreteGaussianGenerator -> SetStd(std);
    // }


// int32_t DiscreteGaussianSampler::GenerateInt() const {
    //     return m_discreteGaussianGenerator -> GenerateInt();
    

    // std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const {
    //     m_discreteGaussianGenerator -> GenerateIntVector(size);
    // }

    // Generator functions
    // std::unique_ptr<DiscreteGaussianSampler> GetSampler() {
    //     return std::make_unique<DiscreteGaussianSampler>();
    // }

    // std::unique_ptr<DiscreteGaussianSampler> GetSamplerWithStd(double std) {
    //     return std::unique_ptr<DiscreteGaussianSampler>(std);
    // }

    int64_t DiscreteGaussianGeneratorGeneric::GenerateInteger(const double center, const double std) {
        return m_discreteGaussianGeneratorGeneric -> GenerateInteger(center, std);
    }

    // Generator functions
    std::unique_ptr<BitGenerator> GetBitGenerator() {
        return std::make_unique<BitGenerator>();
    }

    std::unique_ptr<BaseSampler> GetBaseSampler() {
        return std::make_unique<BaseSampler>();
    }

    std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(const double center, const double std, const BitGenerator& bitGenerator, const BaseSamplerType bst) {
        return std::make_unique<BaseSampler>(center, std, bitGenerator, bst);h
    }

    std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGeneratorWithParams(const BaseSampler** samplers, const double std, const uint32_t b, const double N) {
        return std::make_unique<DiscreteGaussianGeneratorGeneric>(samplers, std, b, N);
    }

    std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGaussianGenerator() {
        return std::make_unique<DiscreteGaussianGeneratorGeneric>();
    }
}
