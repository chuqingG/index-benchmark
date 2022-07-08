#include "art.h"

namespace art
{
    void Art::Insert(const uint32_t value)
    {
        Node* node = root_;

        for (uint8_t offset = 0; offset < 32; offset += 8)
        {
            // get next 8 bit of value as partial key
            const uint8_t partial_key = (value >> offset) & 0xFF;

            // check if partial key already exists
            Node* child_node = node->FindChild(partial_key);

            if (child_node == nullptr)
            {
                // no child for this partial key -> lazy expansion
                const uint64_t tagged_pointer_value = static_cast<uint64_t>(value) << 32 | 0x7;

                node->Insert(partial_key, tagged_pointer_value);
            }
            else
            {
                const auto address_value = reinterpret_cast<uint64_t>(child_node);

                if (Node::IsLazyExpanded(address_value))
                {
                    if (Node::CmpLazyExpansion(address_value, value))
                    {
                        // value has already been inserted
                        return;
                    }
                    else
                    {
                        // expand keys further until they differ
                        // -> create and add new child
                    }
                }
                else
                {
                    // we have a child node for this partial key
                    // -> go to next node
                    node = child_node;
                }
            }
        }
    }

    bool Art::Find(const uint32_t value) const
    {
        Node* node = root_;

        for (uint8_t offset = 0; offset < 32; offset += 8)
        {
            // get next 8 bit of value as partial key
            const uint8_t partial_key = (value >> offset) & 0xFF;

            Node* child_node = node->FindChild(partial_key);

            // check if we have a child
            if (child_node == nullptr)
                return false;

            const auto address_value = reinterpret_cast<uint64_t>(child_node);

            // handle lazy expansion
            if (Node::IsLazyExpanded(address_value))
                return Node::CmpLazyExpansion(address_value, value);

            // go to next node
            node = child_node;
        }

        // compared full value so it exists
        // (since this ART is only for storing 32 bit keys without path compression
        //  or lazy expansion, leaf nodes are not needed)
        return true;
    }

    std::vector<uint32_t> Art::FindRange(const uint32_t from, const uint32_t to) const
    {
        auto result = std::vector<uint32_t>();

        // TODO: Range search

        return result;
    }
}
