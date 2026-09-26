# Map entry `WORD +0x28`: split-copy and reset paths

Three `vm_map_pageable` split paths copy 11 dwords (44 bytes) from the current
`EBX` entry to a newly allocated destination, so the copied byte range includes
offset `+0x28`. The first path later tests `WORD [EBX+0x28] == 0`. The second
path reads that same `EBX` word, decrements it, and stores it to `EBX+0x28`.
The third reads it, increments it, and stores it back. In each latter path,
the immediate copy destination is held separately in a stack local / `EDI`;
the following word update names `EBX`, not that destination.

The `vm_map_fork` path at `0x00177db6` also performs the same 44-byte copy
from `ESI` to the newly allocated `EAX` destination, but immediately writes
zero to `WORD [EAX+0x28]`. This is an explicit post-copy reset of that
destination on this path.

These are local static data-flow facts. They establish neither the semantic
meaning of the word, whether every copy path reaches a later update, nor a
runtime value, ownership, or lifetime. Open Item 1 remains **in progress**.
