#pragma once

#include "openfhe/core/math/discretegaussiangeneratorgeneric.h"
#include "openfhe/core/math/discretegaussiangenerator-impl.h"
#include "openfhe/core/math/discretegaussiangenerator.h"
#include "openfhe/core/lattice/hal/lat-backend.h"

namespace openfhe {
    using DiscreteGaussianGeneratorGeneric = bigintdyn::DiscreteGaussianGeneratorGeneric;
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

    // class BaseSamplerPtr final {
    //     std::shared_ptr<BaseSampler> m_baseSampler;

    //     public:
    //         BaseSamplerPtr() = default;
    //         explicit BaseSamplerPtr(const double center, const double std, const BitGeneratorPtr& bitGenerator, const BaseSamplerType type);
    //         BaseSamplerPtr(std::shared_ptr<BaseSampler>&& baseSampler) noexcept;
    //         BaseSamplerPtr(const BaseSamplerPtr&) = delete;
    //         BaseSamplerPtr(BaseSamplerPtr&&) = delete;
    //         BaseSamplerPtr& operator=(const BaseSamplerPtr&) = delete;
    //         BaseSamplerPtr& operator=(const BaseSamplerPtr&&) = delete;

    //         [[nodiscard]] int64_t BaseSamplerGenerateInteger() const; 
    // };

    // class DiscreteGaussianGeneratorPtr final {
    //     std::shared_ptr<DiscreteGaussianGeneratorImpl> m_discreteGaussianGeneratorGeneric;

    //     public:
    //         DiscreteGaussianGeneratorPtr() = default;
    //         DiscreteGaussianGeneratorPtr(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianGeneratorGeneric) noexcept;
    //         DiscreteGaussianGeneratorPtr(const DiscreteGaussianGeneratorPtr&) = delete;
    //         DiscreteGaussianGeneratorPtr(DiscreteGaussianGeneratorPtr&&) = delete;
    //         DiscreteGaussianGeneratorPtr& operator=(const DiscreteGaussianGeneratorPtr&) = delete;
    //         DiscreteGaussianGeneratorPtr& operator=(const DiscreteGaussianGeneratorPtr&&) = delete;

    //         [[nodiscard]] int64_t GenerateInteger(const double center, const double std) const;
    // };

    // Generator functions
    // [[nodiscard]] std::unique_ptr<BitGeneratorPtr> GetBitGenerator();
    [[nodiscard]] std::unique_ptr<BitGenerator> GetBitGenerator();
    [[nodiscard]] std::unique_ptr<BitGeneratorPtr> GetBitGeneratorPtr();

    // [[nodiscard]] std::unique_ptr<BaseSamplerPtr> GetBaseSampler();
    // [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(const double center, const double std, const BitGeneratorPtr& bitGenerator, const BaseSamplerType type);
    [[nodiscard]] std::unique_ptr<BaseSampler> GetBaseSamplerWithParams(const double center, const double std, BitGenerator* bitGenerator, const BaseSamplerType type);

    // [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorPtr> GetGenerator();
    [[nodiscard]] std::unique_ptr<DiscreteGaussianGeneratorGeneric> GetGeneratorWithParams(BaseSampler* samplers, const double std, const int64_t b, const double N);
} // openfhe
