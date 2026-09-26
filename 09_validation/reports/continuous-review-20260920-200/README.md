# Second 44-byte callback setter fills the prior writer gap

The complete literal-base inventory has fourteen occurrences in seven bodies. Five bodies only compare, read, or scan the table. Three bodies mutate it: `0x001a9c6c` and `0x001a9d30` both calculate the 44-byte indexed cell, apply the count gate, and store all eleven dwords from stack arguments; `0x001a9dec` resets all eleven dwords by `REP MOVSD`. Both setters include the callback reader field at `+0x20`.

The first setter has one direct caller, the second has zero direct relative callers, and reset has one. The zero count for the second setter leaves indirect/table/non-exported entry possible; it must not be treated as unreachable. This closes a literal-base inventory omission but does not resolve alias writers, runtime table state, byte source, or callback lifetime. Open Item 1 remains **in progress**.
