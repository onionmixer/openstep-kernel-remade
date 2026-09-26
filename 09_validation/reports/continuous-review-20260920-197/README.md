# Selected direct address bytes do not occur outside exported bodies

The original `__text` has 851,436 bytes, of which full-pass5 function bodies cover 824,512, leaving 26,924 bytes outside those bodies. Python scanned all `__text` byte offsets for the eight selected 32-bit addresses used by the page initializer, object template, pmap tables, and callback table. Every occurrence falls within an exported function body; the outside-body count is zero for all eight addresses.

This closes one narrow gap in prior export-body inventories: no uncovered `__text` byte sequence directly embeds any selected address. It does not establish that every occurrence is an executing operand, nor rule out pointer aliases, computed addresses, bulk operations, non-text writers, runtime execution, or lifetime. Open Item 1 remains **in progress**.
