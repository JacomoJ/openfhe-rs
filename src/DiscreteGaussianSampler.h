#pragma once

#include "openfhe/core/math/discretegaussiangeneratorgeneric.h"
#include "openfhe/core/math/discretegaussiangenerator-impl.h"
#include "openfhe/core/math/discretegaussiangenerator.h"
#include "openfhe/core/lattice/hal/lat-backend.h"

namespace openfhe {
    using DiscreteGaussianGeneratorImpl = lbcrypto::DiscreteGaussianGeneratorImpl<lbcrypto::NativeInteger>;
    using BitGenerator = lbcrypto::BitGenerator;
    using GetBaseSampler = lbcrypto::BaseSampler;
    using BaseSamplerType = lbcrypto::BaseSamplerType;

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
        std::shared_ptr<DiscreteGaussianGeneratorImpl> m_discreteGaussianGeneratorGeneric;

        public:
            DiscreteGaussianGeneratorGeneric() = default;
            DiscreteGaussianGeneratorGeneric(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianGeneratorGeneric) noexcept;
            DiscreteGaussianGeneratorGeneric(DiscreteGaussianGeneratorGeneric&) = delete;
            DiscreteGaussianGeneratorGeneric(DiscreteGaussianGeneratorGeneric&&) = delete;
            DiscreteGaussianGeneratorGeneric& operator=(const DiscreteGaussianGeneratorGeneric&) = delete;
            DiscreteGaussianGeneratorGeneric& operator=(const DiscreteGaussianGeneratorGeneric&&) = delete;

            [[nodiscard]] int64_t GenerateInteger(const double center, const double std);
    }

    // Generator functions
    [[nodiscard]] std::unique_ptr<BitGenerator> GetBitGenerator();

    [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSampler();
    [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(const double center, const double std, const BitGenerator& bitGenerator, const BaseSamplerType);

    [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGenerator();
    std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGeneratorWithParams(const BaseSampler** samplers, const double std, const uint32_t b, const double N);
} // openfhe
