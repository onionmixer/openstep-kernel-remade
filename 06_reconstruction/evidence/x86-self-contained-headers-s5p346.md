# Self-contained headers, plan 346 (S5-P335)

Before this plan, stage_headers.py read 25 headers for already recorded x86 objects
directly from Darwin 0.1 (its fallback when neither 07_kernel nor the 4.2 SDK has the
name; these were not reported as mach/bsd_not_adopted).  The set was taken from the
221 `08_build/runs/tools/*-rec-stage.manifest.json` files: 52 distinct Darwin headers,
15 of them other-architecture branches (ppc/hppa/sparc/m68k, machdep/machine), 37
eligible, 12 already given 07 copies by plans 344-345, 25 remaining.

Placed in 07_kernel (all with PROVENANCE and MODIFICATIONS rows, plan 346):

- 22 Darwin-only headers as D030 copies (head comment replaced, body verbatim):
  nextdev_private/driverkit/ EventInput.h, IOBufDevice.h, IODeviceKernPrivate.h,
  IODeviceParams.h, IOPower.h, KeyMap.h, SCSIDiskKern.h, SCSIGeneric.h,
  SCSIGenericPrivate.h, configTableKern.h, configTablePrivate.h, driverServer.h,
  i386/IOVPCodeDisplay.h, i386/driverServer.h, i386/vpCode.h, memcpy.h;
  src/driverkit/ KernBusInterrupt.h, KernBusInterruptPrivate.h, KernBusPrivate.h,
  KernDevicePrivate.h, KernLock.h, autoconfCommon.h.
- src/driverkit/KernStringList.h: the 4.2 SDK header verbatim (real-machine SHA-256
  20d12c3130cb5d0429d883ddefe17a89aef4b55781574d840238558891d07f33; the Darwin text is
  a licence block followed by these bytes).
- src/kern/parallel.h: NeXTMach mk-108.1/kern/parallel.h verbatim (pinned commit
  f6bdb9c3268f0eadc545d41bcc0564453b17001e; no Mach4 counterpart; D022).  With KERNEL and
  KERNEL_BUILD defined and KERNEL_FEATURES undefined both versions import <cpus.h>.
- src/ipc/ipc_machdep.h: Mach4 kernel/ipc/ipc_machdep.h verbatim (pinned commit
  69fa77870f20d854c875135e116ebc80b118e7ff); differs from Darwin only in alpha/__alpha.

Regression (scratchpad regress346.py; runs `<run>-rg3`): the 37 recorded runs that read
any of the 25 were re-staged with the same stage_headers flags and rebuilt with the same
command files (51 EXPECT outputs).  Staged file sets were compared with the pre-change
closures (stage_headers.closure on 07 before the copies): no change outside the 25
headers and `src/bsd/sys/features.h` (pulled in by the NeXTMach parallel.h's inactive
branch).  Objects were compared per section (segname, sectname, addr, size, align, flags,
bytes, relocations) and per non-stab symbol (name, type, sect, desc, value): 50 of 51
identical.  The exception, s5p155-it2 sys_generic.o (F and N), differs only in the name
of one static local symbol (`_flags.110` -> `_flags.112`; same type, section, value);
section bytes and relocations are identical, l1_compare gives OBJECT_MATCH for the
rebuilt F object, and the original kernel symbol table has no numbered static-local
symbols, so this is not a difference visible against the original.
