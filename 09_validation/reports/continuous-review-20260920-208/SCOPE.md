# Scope — callback-table registration/reset wrapper protocol

Only original x86 `mach_kernel` bytes and full-pass5 function bodies derived
from that binary are used. Python calculated raw offsets and checked cited
instruction bytes. Export and Objective-C selector names are identifiers only;
the findings rely on stack/register flow and equal selector-address operands.

This report establishes a matched static wrapper protocol. It does not prove
receiver identity, Objective-C dispatch semantics, call ordering, execution,
or callback-table lifetime at runtime.
