# Authorized original inputs contain no runtime-observation boot configuration

The authorized `03_original` tree contains one nonempty x86 binary input:
`x86/binaries/mach_kernel` (1,117,920 bytes, with the recorded kernel SHA-256).
The remaining x86 files are inventory/metadata outputs plus `.gitkeep` files.
There is no original boot medium, bootloader, emulator invocation record,
execution trace, or runtime memory snapshot under `03_original`.

`qemu-system-i386` is installed in the analysis environment, but that does not
supply an original boot configuration. Introducing a boot image, loader, or
reference system would violate the current original-kernel-only scope. Thus
runtime observations needed for actual page/object/map/pmap values and
lifetime cannot presently be obtained from the authorized inputs.

This is an input-availability finding, not a claim that the original kernel
cannot run in a properly supplied historical environment. Static analysis can
continue to narrow instruction-level boundaries, but it cannot by itself prove
the Open Item 1 runtime-value and lifetime requirements. Open Item 1 remains
**in progress**.
