# Scope — callback reset source and `_smmap` filter path

Only original x86 `mach_kernel` bytes and full-pass5 bodies derived from that
binary are used. Python calculated the 44-byte reset length, resolved the
`__DATA,__data` file offset, unpacked the eleven source dwords, and checked all
cited instruction bytes with `VA - 0x00100000` file offsets.

The result is limited to the shown reset copy and `_smmap` branch. It does not
identify callback semantics, runtime index provenance, synchronization, or
object/table lifetime.
