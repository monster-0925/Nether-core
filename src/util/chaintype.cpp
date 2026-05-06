// Copyright (c) 2023-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <util/chaintype.h>

#include <util/check.h>

#include <optional>
#include <string>

std::string ChainTypeToString(ChainType chain)
{
    switch (chain) {
    case ChainType::MAIN:
        return "main";
    case ChainType::TESTNET:
        return "test";
    case ChainType::TESTNET4:
        return "testnet4";
    case ChainType::SIGNET:
        return "signet";
    case ChainType::REGTEST:
        return "regtest";
    case ChainType::COMEDIAN:
        return "comedian";
    }
    assert(false);
}

std::optional<ChainType> ChainTypeFromString(std::string_view chain)
{
    if (chain == "comedian") return ChainType::COMEDIAN;
    if (chain == "main") return ChainType::MAIN;
    if (chain == "test") return ChainType::TESTNET;
    if (chain == "testnet4") return ChainType::TESTNET4;
    if (chain == "signet") return ChainType::SIGNET;
    if (chain == "regtest") return ChainType::REGTEST;

    return std::nullopt;
}

