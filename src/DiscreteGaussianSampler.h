#pragma once

#include "openfhe/core/math/discretegaussiangeneratorgeneric.h"
#include "openfhe/core/math/discretegaussiangenerator-impl.h"
#include "openfhe/core/math/discretegaussiangenerator.h"
#include "openfhe/core/lattice/hal/lat-backend.h"

namespace openfhe {
    using DiscreteGaussianGeneratorGeneric = bigintdyn::DiscreteGaussianGeneratorGeneric;
    using DiscreteGaussianGeneratorImpl = lbcrypto::DiscreteGaussianGeneratorImpl<lbcrypto::NativeVector>;
    using BitGenerator = lbcrypto::BitGenerator;
    using BaseSampler = lbcrypto::BaseSampler;
    using BaseSamplerType = lbcrypto::BaseSamplerType;

    class BitGeneratorPtr final {
        std::shared_ptr<BitGenerator> m_bitGenerator;

        public:
            BitGeneratorPtr() = default;
            BitGeneratorPtr(std::shared_ptr<BitGenerator>&& bitGenerator) noexcept;
            BitGeneratorPtr(const BitGeneratorPtr&) = delete;
            BitGeneratorPtr(BitGeneratorPtr&&) = delete;
            BitGeneratorPtr& operator=(const BitGeneratorPtr&) = delete;
            BitGeneratorPtr& operator=(const BitGeneratorPtr&&) = delete;

            [[nodiscard]] const std::shared_ptr<BitGenerator>& GetRef() const noexcept;
    };

    class DiscreteGaussianPtr final {
        std::shared_ptr<DiscreteGaussianGeneratorImpl> m_discreteGaussianGenerator;
        
    public:
        DiscreteGaussianPtr() = default;
        DiscreteGaussianPtr(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& DiscreteGaussianPtrDiscreteGaussianPtr) noexcept;
        DiscreteGaussianPtr(DiscreteGaussianPtr&) = delete;
        DiscreteGaussianPtr(DiscreteGaussianPtr&&) = delete;
        DiscreteGaussianPtr& operator=(const DiscreteGaussianPtr&) = delete;
        DiscreteGaussianPtr& operator=(const DiscreteGaussianPtr&&) = delete;

        // [[nodiscard]] const std::shared_ptr<DiscreteGaussianPtr>& GetRef() const noexcept;
        // [[nodiscard]] std::shared_ptr<DiscreteGaussianPtr>& GetRef() const noexcept;

        // void Initialize() const;
        // void SetStd(const double std);
        // [[nodiscard]] int32_t GenerateInt() const noexcept;
        // [[nodiscard]] std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const;
        // [[nodiscard]] int32_t GenerateInteger() const;
    };

    // Generator functions
    [[nodiscard]] std::unique_ptr<BitGenerator> GetBitGenerator();
    [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(const double center, const double std, BitGenerator* bitGenerator, const BaseSamplerType type);
    [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorImpl> GetGeneratorWithParams(const double std);
    [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGeneratorGenericWithParams(BaseSampler** samplers, const double std, const int64_t b, const double N);
} // openfhe
