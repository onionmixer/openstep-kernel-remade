# Kernel-only QEMU probe does not yield an original-kernel runtime observation

With no disk, bootloader, or other external input, QEMU accepted the kernel
argument but a 15-second serial probe produced no kernel output and ended only
because the imposed timeout sent signal 15. A separate `-S` monitor probe
observed the initial reset state at `CS.base=0xffff0000`, `EIP=0x0000fff0`.
After a short `cont`, the monitor observation was `CS.base=0x0005b000`,
`EIP=0x0000792a`.

Python calculates those linear values as `0xfffffff0` and `0x0006292a`.
Neither lies in the linked original `__text` range
`0x001012d0..0x001d10bc` (exclusive end). This is insufficient to assert a
boot failure or to identify guest code: linked virtual addresses need not by
themselves describe every probe execution state. It does establish that this
unconfigured probe supplied no observation of the required VM startup or
runtime memory values.

No boot image, loader, reference kernel, or external source was used. The
runtime-value/lifetime portion of Open Item 1 remains unavailable without an
original boot configuration or an authorized runtime trace/snapshot. Open Item
1 remains **in progress**.
