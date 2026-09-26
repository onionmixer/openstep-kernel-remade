# Page-template field addresses have no non-text pointer aliases

The template base and ten selected field addresses were scanned across the complete original file. Every field address used by the observed startup writer occurs only in `__text`. The template base and the separate `+0x30` counter have one additional non-text occurrence each; Python parses both as the `n_value` field of a Mach-O symbol record, not initialized data.

This narrows static direct-address alias candidates for the startup writer and template copy. It does not rule out arithmetic aliases, string/bulk writes, dynamic pointers, loader behavior, or runtime page lifetime. Open Item 1 remains **in progress**.
