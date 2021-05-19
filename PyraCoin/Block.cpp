#include "Block.h"

Block::Block(const uint64_t index, const time_t timestamp, const BlockData data, const string previousHash) :
    index(index), timestamp(timestamp), data(data), previousHash(previousHash), hash(CalculateHash())
{}

string Block::CalculateHash() const
{
    SHA256 sha256;
    std::stringstream ss;

    ss << index << timestamp << data.GetSender() << data.GetReceiver() << data.GetTransactionAmount();

    return sha256(ss.str());
}

std::ostream& operator<<(std::ostream& out, const Block& block)
{
    out << "Block{index=" << block.index
        << ";timestamp=" << block.timestamp
        << ";data=" << block.data << "}"
        << "\n;hash=" << block.GetHash()
        << "\n;previousHash=" << block.GetPreviousHash();

    return out;
}
