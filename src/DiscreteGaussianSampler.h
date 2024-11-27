#pragma once

#include "openfhe/core/math/discretegaussiangeneratorgeneric.h"
#include "openfhe/core/math/discretegaussiangenerator-impl.h"
#include "openfhe/core/math/discretegaussiangenerator.h"
#include "openfhe/core/lattice/hal/lat-backend.h"

namespace openfhe {
    using DiscreteGaussianGeneratorImpl = lbcrypto::DiscreteGaussianGeneratorImpl<lbcrypto::NativeInteger>;

    class DiscreteGaussianSampler final {
        std::shared_ptr<DiscreteGaussianGeneratorImpl> m_discreteGaussianGenerator;
        
    public:
        DiscreteGaussianSampler() = default;
        DiscreteGaussianSampler(std::shared_ptr<DiscreteGaussianGeneratorImpl>&& discreteGaussianSampler) noexcept;

        void Initialize() const;
        int32_t GenerateInt() const;
        // [[nodiscard]] std::shared_ptr<int64_t> GenerateIntVector(const uint32_t size) const;
        // [[nodiscard]] int32_t GenerateInteger() const;
    };

    // Generator function
    [[nodiscard]] std::unique_ptr<DiscreteGaussianSampler> GetSampler();

}