# Scope — map-record-derived object `+0x30` transitions

Only original x86 `mach_kernel` bytes and full-pass5 body exports derived from
that binary are used. Python calculated all offsets from the Mach base and
read each cited original instruction byte.  This report follows only explicit
register dataflow in `0x00176084` and `0x00176164`; labels and decompiler
types are not used as proof of field meaning.

It proves selected record-to-pointer transitions and their conditional static
control flow. It does not constitute a binary-wide alias, concurrency, or
runtime-lifetime closure.
