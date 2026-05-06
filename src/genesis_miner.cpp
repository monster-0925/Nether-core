#include <iostream>
#include "primitives/block.h"
#include "chainparams.h"
#include "uint256.h"
#include "util/strencodings.h"

int main() {
    const char* pszTimestamp = "The Times 01/May/2026 Power returns to the network, not the gatekeepers";

    CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a671...");

    uint32_t nTime = 1746100000;   // you can adjust
    uint32_t nBits = 0x1d00ffff;   // same as Bitcoin test unless changed
    uint32_t nNonce = 0;

    CBlock genesis = CreateGenesisBlock(nTime, nNonce, nBits, 1, 50 * COIN);

    std::cout << "Mining genesis...\n";

    while (true) {
        genesis.nNonce = nNonce;

        uint256 hash = genesis.GetHash();

        // Print every 100k tries
        if (nNonce % 100000 == 0)
            std::cout << "Nonce: " << nNonce << " Hash: " << hash.ToString() << "\n";

        // VERY IMPORTANT: target check
        if (UintToArith256(hash) <= UintToArith256(uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"))) {
            std::cout << "\nFOUND GENESIS!\n";
            std::cout << "Nonce: " << nNonce << "\n";
            std::cout << "Hash: " << hash.ToString() << "\n";
            break;
        }

        nNonce++;
    }

    return 0;
}
