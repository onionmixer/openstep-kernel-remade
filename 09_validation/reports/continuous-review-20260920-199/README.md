# `_smmap` has a static data-table indirect entry

The lack of a direct relative `CALL` caller for `_smmap` does not mean it lacks a static entry. Original data at `0x001da270` contains function pointer `0x00106e58`. The preceding dword at `0x001da26c` is 6. Python calculates this as table index 71 for an 8-byte record rooted at `0x001da034`; the raw table count is 184.

The dispatcher checks its index against that count, computes `0x001da034 + 8*index`, later loads the selected record's `+4` dword, then executes `CALL EDX`. This supplies a concrete indirect path to the callback reader function and explains why direct-call inventory was incomplete.

The runtime index, trap reachability, arguments, and callback/table lifetime remain unproven. Open Item 1 remains **in progress**.
