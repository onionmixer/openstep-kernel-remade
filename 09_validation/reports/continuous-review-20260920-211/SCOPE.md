# Scope — direct-literal accesses to selected VM pmap bootstrap globals

Only original x86 `mach_kernel` bytes and full-pass5 bodies derived from that
binary are used. Python normalized hexadecimal operands to integers, counted
export instruction occurrences, scanned raw `__text` for each little-endian
32-bit literal, calculated membership in exported body ranges, and verified
cited instruction encodings at file offset `VA - 0x00100000`.

The scan covers only five selected addresses and direct literal encodings. It
does not resolve register-derived, pointer-derived, bulk, non-text, loader, or
runtime writers, nor establish semantics or ownership.
