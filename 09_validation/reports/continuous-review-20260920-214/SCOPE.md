# Scope — kernel-only QEMU runtime-observation probe

The probe used the original `mach_kernel` as the only guest-supplied file.
QEMU monitor output was observed without attaching a disk or bootloader.
Python calculated the two reported `CS.base + EIP` values and range-membership
against the original linked `__text` metadata. No external image, source, or
runtime artifact was consulted.

This is one unconfigured emulator probe, not an emulation-compatibility test
or a proof about historical boot behavior.
