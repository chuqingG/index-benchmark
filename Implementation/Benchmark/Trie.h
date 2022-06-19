#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>

class Trie {
private:
    /**
     * We store the complete trie in a single hashmap.
     *
     * The key is a 32 bit integer where the first 28 bits (0th up to 27th) represent the current node index
     * and the last 4 bits represent the current symbol used (this means the trie implementation has a span of 4).
     *
     * We can differentiate a maximum of 2^28 or approx. 268 million different nodes which is enough for storing
     * 32 bit integers.
     *
     * The value is again a 32 bit integer with the first 28 bits representing the node index this key is referring
     * to.
     *
     * Note that since we're only storing exactly 32bit keys with a static span of 4 we don't need to mark nodes
     * as leaves as every node at the 4th layer must be a leaf indicating the presence of the given 32bit value.
     */
    std::unordered_map<uint32_t, uint32_t> trie;

public:
    /**
     * Inserts a 32 bit value into the trie.
     *
     * @param value the value to insert
     */
    void insert(uint32_t value);

    /**
     * Checks if a 32 bit value exists in the trie.
     *
     * @param value the value to search for
     * @return true if the value exists otherwise false
     */
    bool find(uint32_t value) const;

    std::vector<uint32_t> find_range(uint32_t from, uint32_t to) const;
};

