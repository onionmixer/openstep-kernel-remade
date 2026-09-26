# Non-text selected-address matches are Mach-O symbol values

Report 197 found no selected address byte sequence outside exported bodies in `__text`. Extending that scan to the complete original file finds the remaining non-text matches only in `__LINKEDIT`'s `LC_SYMTAB` records: each is the `n_value` field of a 32-bit `nlist` entry. The page globals, object template, callback base, and one pmap-labelled table have these symbol metadata records; the object `+0x30` absolute address and the other pmap table have no non-text raw match.

Thus the raw whole-file scan identifies no selected address occurrence in mapped initialized data that could directly serve as a static pointer alias. This does not exclude dynamic aliases, computed addresses, bulk operations, or runtime changes. Open Item 1 remains **in progress**.
