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

    DiscreteGaussianSampler::DiscreteGaussianSampler(std::shared_ptr<m_discreteGaussianGeneratorGeneric>&& discreteGaussianSampler) noexcept 
        : m_discreteGaussianGeneratorGeneric(std::move(discreteGaussianSampler))
    { }

    // getRefs
    const std::shared_ptr<BitGenerator>& BitGenerator::GetRef() const noexcept {
        return m_bitGenerator;
    }

    const std::shared_ptr<BaseSampler>& BaseSampler::GetRef() const noexcept {
        return m_baseSampler;
    }

    const std::shared_ptr<DiscreteGaussianSampler>& DiscreteGaussianSampler::GetRef() const noexcept {
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

    std::unique_ptr<BitGenerator> GetBitGenerator() {
        return std::unique_ptr<BitGenerator>();
    }

    std::unique_ptr<BaseSampler> GetBaseSampler() {
        return std::unique_ptr<BaseSampler>();
    }

    std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGenerator() {
        return std::unique_ptr<DiscreteGaussianGeneratorGeneric>();
    }
}
