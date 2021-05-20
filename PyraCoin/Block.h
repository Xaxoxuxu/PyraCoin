#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include "Sha256.h"
#include "Transaction.h"

using std::string;
using std::time_t;
using std::to_string;

class Block
{
private:
    const time_t timestamp;
    const Transaction transaction;
    const string previousHash;
    uint64_t nonce;
    string hash;

public:
    Block(time_t timestamp, Transaction transaction, string previousHash);

    string GetHash() const { return hash; }
    string GetPreviousHash() const { return previousHash; }

    string CalculateHash() const;
    void MineBlock(const uint32_t difficulty);
    friend std::ostream& operator<< (std::ostream& out, const Block& block);
};