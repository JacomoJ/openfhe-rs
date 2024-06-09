#include "SerialDeserial.h"

#include "openfhe/pke/cryptocontext-ser.h"

#include "Ciphertext.h"
#include "CryptoContext.h"
#include "PublicKey.h"

namespace openfhe
{

template <typename ST, typename Object>
[[nodiscard]] bool SerialDeserial(const std::string& location,
    bool (* const funcPtr) (const std::string&, Object&, const ST&), Object& object)
{
    return funcPtr(location, object, ST{});
}
template <typename Object>
[[nodiscard]] bool Serial(const std::string& location, Object& object, const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, decltype(object.GetRef())>(location,
            lbcrypto::Serial::SerializeToFile, object.GetRef());
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, decltype(object.GetRef())>(location,
            lbcrypto::Serial::SerializeToFile, object.GetRef());
    }
    return false;
}
template <typename Object>
[[nodiscard]] bool Deserial(const std::string& location, Object& object,
    const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, decltype(object.GetRef())>(location,
            lbcrypto::Serial::DeserializeFromFile, object.GetRef());
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, decltype(object.GetRef())>(location,
            lbcrypto::Serial::DeserializeFromFile, object.GetRef());
    }
    return false;
}

template <typename ST, typename Stream, typename FStream, typename... Types>
[[nodiscard]] bool SerialDeserial(const std::string& location,
    bool (* const funcPtr) (Stream&, const ST&, Types... args), Types... args)
{
    const auto close = [](FStream* const fs){ if (fs->is_open()) { fs->close(); } };
    const std::unique_ptr<FStream, decltype(close)> fs(
        new FStream(location, std::ios::binary), close);
    return fs->is_open() ? funcPtr(*fs, ST{}, args...) : false;
}

// Ciphertext
bool DeserializeCiphertextFromFile(const std::string& ciphertextLocation,
    CiphertextDCRTPoly& ciphertext, const SerialMode serialMode)
{
    return Deserial(ciphertextLocation, ciphertext, serialMode);
}
bool SerializeCiphertextToFile(const std::string& ciphertextLocation,
    const CiphertextDCRTPoly& ciphertext, const SerialMode serialMode)
{
    return Serial(ciphertextLocation, ciphertext, serialMode);
}

// CryptoContextDCRTPoly
bool DeserializeCryptoContextFromFile(const std::string& ccLocation,
    CryptoContextDCRTPoly& cryptoContext, const SerialMode serialMode)
{
    return Deserial(ccLocation, cryptoContext, serialMode);
}
bool SerializeCryptoContextToFile(const std::string& ccLocation,
    const CryptoContextDCRTPoly& cryptoContext, const SerialMode serialMode)
{
    return Serial(ccLocation, cryptoContext, serialMode);
}

// EvalAutomorphismKey
bool DeserializeEvalAutomorphismKeyFromFile(const std::string& automorphismKeyLocation,
    const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::istream, std::ifstream>(
            automorphismKeyLocation, CryptoContextImpl::DeserializeEvalAutomorphismKey);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::istream, std::ifstream>(
            automorphismKeyLocation, CryptoContextImpl::DeserializeEvalAutomorphismKey);
    }
    return false;
}
bool SerializeEvalAutomorphismKeyByIdToFile(const std::string& automorphismKeyLocation,
    const SerialMode serialMode, const std::string& id)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            automorphismKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey, id);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            automorphismKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey, id);
    }
    return false;
}
bool SerializeEvalAutomorphismKeyToFile(const std::string& automorphismKeyLocation,
    const CryptoContextDCRTPoly& cryptoContext, const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            automorphismKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey,
            cryptoContext.GetRef());
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            automorphismKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey,
            cryptoContext.GetRef());
    }
    return false;
}

// EvalMultKey
bool DeserializeEvalMultKeyFromFile(const std::string& multKeyLocation,
    const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::istream, std::ifstream>(
            multKeyLocation, CryptoContextImpl::DeserializeEvalMultKey);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::istream, std::ifstream>(
            multKeyLocation, CryptoContextImpl::DeserializeEvalMultKey);
    }
    return false;
}
bool SerializeEvalMultKeyByIdToFile(const std::string& multKeyLocation,
    const SerialMode serialMode, const std::string& id)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            multKeyLocation, CryptoContextImpl::SerializeEvalMultKey, id);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            multKeyLocation, CryptoContextImpl::SerializeEvalMultKey, id);
    }
    return false;
}
bool SerializeEvalMultKeyToFile(const std::string& multKeyLocation,
    const CryptoContextDCRTPoly& cryptoContext, const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            multKeyLocation, CryptoContextImpl::SerializeEvalMultKey, cryptoContext.GetRef());
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            multKeyLocation, CryptoContextImpl::SerializeEvalMultKey, cryptoContext.GetRef());
    }
    return false;
}

// EvalSumKey
bool DeserializeEvalSumKeyFromFile(const std::string& sumKeyLocation, const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::istream, std::ifstream>(
            sumKeyLocation, CryptoContextImpl::DeserializeEvalAutomorphismKey);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::istream, std::ifstream>(
            sumKeyLocation, CryptoContextImpl::DeserializeEvalAutomorphismKey);
    }
    return false;
}
bool SerializeEvalSumKeyByIdToFile(const std::string& sumKeyLocation,
    const SerialMode serialMode, const std::string& id)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            sumKeyLocation, CryptoContextImpl::SerializeEvalSumKey, id);
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            sumKeyLocation, CryptoContextImpl::SerializeEvalSumKey, id);
    }
    return false;
}
bool SerializeEvalSumKeyToFile(const std::string& sumKeyLocation,
    const CryptoContextDCRTPoly& cryptoContext, const SerialMode serialMode)
{
    if (serialMode == SerialMode::BINARY)
    {
        return SerialDeserial<lbcrypto::SerType::SERBINARY, std::ostream, std::ofstream>(
            sumKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey,
            cryptoContext.GetRef());
    }
    if (serialMode == SerialMode::JSON)
    {
        return SerialDeserial<lbcrypto::SerType::SERJSON, std::ostream, std::ofstream>(
            sumKeyLocation, CryptoContextImpl::SerializeEvalAutomorphismKey,
            cryptoContext.GetRef());
    }
    return false;
}

// PublicKey
bool DeserializePublicKeyFromFile(const std::string& publicKeyLocation,
    PublicKeyDCRTPoly& publicKey, const SerialMode serialMode)
{
    return Deserial(publicKeyLocation, publicKey, serialMode);
}
bool SerializePublicKeyToFile(const std::string& publicKeyLocation,
    const PublicKeyDCRTPoly& publicKey, const SerialMode serialMode)
{
    return Serial(publicKeyLocation, publicKey, serialMode);
}

} // openfhe
