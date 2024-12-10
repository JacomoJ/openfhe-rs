#pragma once

#include "openfhe/core/math/discretegaussiangeneratorgeneric.h"
#include "openfhe/core/math/discretegaussiangenerator-impl.h"
#include "openfhe/core/math/discretegaussiangenerator.h"
#include "openfhe/core/lattice/hal/lat-backend.h"

namespace openfhe {
    using DiscreteGaussianGeneratorImpl = lbcrypto::DiscreteGaussianGeneratorImpl<lbcrypto::NativeInteger>;
    using BitGenerator = lbcrypto::BitGenerator;
    using GetBaseSampler = lbcrypto::BaseSampler;
    using 
    class BitGenerator final {
        std::shared_ptr<BitGenerator> m_bitGenerator;

        public:
            BitGenerator() = default;
            BitGenerator(std::shared_ptr<BitGenerator>&& bitGenerator) noexcept;
            BitGenerator(BitGenerator&) = delete;
            BitGenerator(BitGenerator&&) = delete;
            BitGenerator& operator=(const BitGenerator&) = delete;
            BitGenerator& operator=(const BitGenerator&&) = delete;

            [[nodiscard]] const std::shared_ptr<BitGenerator>& GetRef() const noexcept;

    }

    class BaseSampler final {
        std::shared_ptr<BaseSampler> m_baseSampler;

        public:
            BaseSampler() = default;
            BaseSampler(std::shared_ptr<BaseSampler>&& baseSampler) noexcept;
            BaseSampler(BaseSampler&) = delete;
            BaseSampler(BaseSampler&&) = delete;
            BaseSampler& operator=(const BaseSampler&) = delete;
            BaseSampler& operator=(const BaseSampler&&) = delete;
    }

    class DiscreteGaussianGeneratorGeneric final {
        std::shared_ptr<DiscreteGaussianGeneratorGeneric> m_discreteGaussianGeneratorGeneric;

        public:
            DiscreteGaussianGeneratorGeneric() = default;
            DiscreteGaussianGeneratorGeneric(std::shared_ptr<DiscreteGaussianGeneratorGeneric>&& discreteGaussianGeneratorGeneric) noexcept;
            DiscreteGaussianGeneratorGeneric(DiscreteGaussianGeneratorGeneric&) = delete;
            DiscreteGaussianGeneratorGeneric(DiscreteGaussianGeneratorGeneric&&) = delete;
            DiscreteGaussianGeneratorGeneric& operator=(const DiscreteGaussianGeneratorGeneric&) = delete;
            DiscreteGaussianGeneratorGeneric& operator=(const DiscreteGaussianGeneratorGeneric&&) = delete;
    }

    // class DiscreteGaussianSampler final {
    //     std::shared_ptr<DiscreteGaussianGeneratorImpl> m_discreteGaussianGenerator;
        
    // public:
    //     DiscreteGaussianSampler() = default;
    //     DiscreteGaussianSampler(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianSampler) noexcept;
    //     DiscreteGaussianSampler(DiscreteGaussianSampler&) = delete;
    //     DiscreteGaussianSampler(DiscreteGaussianSampler&&) = delete;
    //     DiscreteGaussianSampler& operator=(const DiscreteGaussianSampler&) = delete;
    //     DiscreteGaussianSampler& operator=(const DiscreteGaussianSampler&&) = delete;

    //     [[nodiscard]] const std::shared_ptr<DiscreteGaussianSampler>& GetRef() const noexcept;
    //     // [[nodiscard]] std::shared_ptr<DiscreteGaussianSampler>& GetRef() const noexcept;

    //     void Initialize() const;
    //     void SetStd(const double std);
    //     int32_t GenerateInt() const;
    //     // [[nodiscard]] std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const;
    //     // [[nodiscard]] int32_t GenerateInteger() const;
    // };

    // Generator function
    // [[nodiscard]] std::unique_ptr<DiscreteGaussianSampler> GetSampler();
    // [[nodiscard]] std::unique_ptr<DiscreteGaussianSampler> GetSamplerWithStd(double std);

    [[nodiscard]] std::unique_ptr<BitGenerator> GetBitGenerator();
    [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSampler();
    [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGenerator();
} // openfhe
