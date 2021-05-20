#include "Block.h"

Block::Block(const uint64_t index, const time_t timestamp, const BlockData data, const string previousHash) :
    index(index), timestamp(timestamp), data(data), previousHash(previousHash), nonce(0), hash(CalculateHash())
{}

string Block::CalculateHash() const
{
    SHA256 sha256;
    std::stringstream ss;

    ss << this->index << this->timestamp << this->data.GetSender() << this->data.GetReceiver() << this->data.GetTransactionAmount() << this->nonce;

    return sha256(ss.str());
}

void Block::MineBlock(const uint32_t difficulty)
{
    const string difficultyString(difficulty, '0');
    while (this->hash.substr(0, difficulty) != difficultyString)
    {
        this->nonce++;
        this->hash = CalculateHash();
    }
}

std::ostream& operator<<(std::ostream& out, const Block& block)
{
    out << "Block{index=" << block.index
        << ";timestamp=" << block.timestamp
        << ";data=" << block.data
        << ";nonce=" << block.nonce << "}"
        << "\n;hash=" << block.GetHash()
        << "\n;previousHash=" << block.GetPreviousHash();

    return out;
}