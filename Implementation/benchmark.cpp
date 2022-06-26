#include "benchmark.h"

inline void ArtInsert(art::Art* art, const uint32_t* numbers, const uint32_t size)
{
	for (uint32_t i = 0; i < size; ++i)
	{
		art->Insert(numbers[i]);
	}
}

inline void ArtSearch(const art::Art* art, const uint32_t* numbers, const uint32_t size)
{
	for (uint32_t i = 0; i < size; ++i)
	{
		art->Find(numbers[i]);
	}
}

inline void ArtRangeSearch(const art::Art* art, const std::vector<std::pair<uint32_t, uint32_t>>& numbers)
{
	for (const auto& [from, to] : numbers)
	{
		// TODO: Check once if correct results
		art->FindRange(from, to);
	}
}

inline void TrieInsert(trie::Trie* trie, const uint32_t* numbers, const uint32_t size)
{
	for (uint32_t i = 0; i < size; ++i)
	{
		trie->Insert(numbers[i]);
	}
}

inline void TrieSearch(const trie::Trie* trie, const uint32_t* numbers, const uint32_t size)
{
	for (uint32_t i = 0; i < size; ++i)
	{
		trie->Find(numbers[i]);
	}
}

inline void TrieRangeSearch(const trie::Trie* trie, const std::vector<std::pair<uint32_t, uint32_t>>& numbers)
{
	for (const auto& [from, to] : numbers)
	{
		// TODO: Check once if correct results
		trie->FindRange(from, to);
	}
}
