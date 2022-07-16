#pragma once

#include "trie.h"
#include "../../benchmark.h"

class TrieBenchmark : public Benchmark
{
public:
    ~TrieBenchmark() override
    {
        delete trie_;
    }

    void InitializeStructure() override
    {
        trie_ = new trie::Trie();
    }

    void DeleteStructure() override
    {
        delete trie_;
        trie_ = nullptr;
    }

    void Insert(const uint32_t* numbers, const uint32_t size) override
    {
        auto& trie = *trie_;

        for (uint32_t i = 0; i < size; ++i)
            trie.Insert(numbers[i]);
    }

    void Search(const uint32_t* numbers, const uint32_t size) override
    {
        for (uint32_t i = 0; i < size; ++i)
            trie_->Find(numbers[i]);
    }

    void RangeSearch(const uint32_t* numbers, const uint32_t size) override
    {
        for (uint32_t i = 0; i < 2 * size; i += 2)
            trie_->FindRange(numbers[i], numbers[i + 1]);
    }

private:
    trie::Trie* trie_ = nullptr;
};
