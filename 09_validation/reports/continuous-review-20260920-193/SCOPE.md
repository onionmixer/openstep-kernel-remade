# Scope — pmap-labelled constructor direct-call inventory

This audit is restricted to the original `mach_kernel` x86 bytes and the
full-pass5 function export derived from that binary. It inventories direct
relative `CALL` instructions to `0x001353b0`, `0x00134f94`, and `0x00135df4`,
then decodes every reported call site from the original bytes with Python and
Capstone x86-32. It also records the constructor's observed table-pointer
stores and its observed failure-path calls.

It does not assign source-level semantics to exporter labels, infer the effect
of cleanup targets, prove allocation success, follow indirect calls or aliases,
or establish runtime object/table lifetime.
