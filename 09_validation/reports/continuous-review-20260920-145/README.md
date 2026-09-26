# PV chain removal and lifetime boundary (original x86 bytes)

## Scope

Open item 2 of `continuous-review-20260920-106/OPEN_ITEMS.md`: establish the
PV-list unlink, node-reclamation, lock, and interrupt-priority boundaries in
`_pmap_remove_all`.  This report inspects only the original x86 kernel bytes.
Names from the function export are labels, not evidence of behaviour.

## Inputs

* `03_original/x86/binaries/mach_kernel`
* `04_ghidra/exports/x86/full-pass5/functions.json` (labels only)
* Python Capstone disassembly of `0x0018fb0c..0x0018fd1b`

## Original-byte evidence

`_pmap_remove_all` begins at `0x0018fb0c`.  It validates argument `[ebp+8]`
against absolute range globals `0x001e247c` and `0x001e2480`; either failed
range branch goes to `0x0018fd20`, past the `_splx` call.  For an in-range
address it directly calls `0x0018b964` at `0x0018fb30`, saving `EAX` in
`[ebp-0x14]`.

The export labels the first target `_splvm` and the final target at
`0x0018b544` `_splx`.  The raw prologue at `0x0018b544` includes `cli` and
stores its argument to absolute `0x001e7714`, supporting the limited
classification of the latter call as restoration of the saved priority state;
the exact higher-level locking policy remains outside this report.

The address calculation at `0x0018fb3b..0x0018fb5e` sets `[ebp-4]` and
`[ebp-8]` to an indexed address based on absolute `0x001f7ab8`, `0x001f7ae0`,
and `0x001f7ab0`.  It reads `[address+4]` into `[ebp-0x10]`.  Each iteration
later advances that value using:

```
0x0018fd06  mov ecx, [ebp-4]
0x0018fd09  mov ecx, [ecx+4]
0x0018fd0c  mov [ebp-0x10], ecx
0x0018fd0f  test ecx, ecx
0x0018fd11  jne 0x0018fb70
```

Before operating on that entry, the loop acquires a one-word lock at
`[ebp-0x10]+0x0c`: it busy-waits for zero, writes one with `xchg`, and retries
if the exchanged old value was nonzero (`0x0018fb80..0x0018fb92`).  At the end
of the same iteration it writes zero with `xchg [edi+0x0c], eax` at
`0x0018fd03`.

The PV-list reclamation sequence is direct and ordered:

1. At `0x0018fc71`, load `EAX = [[ebp-4]]`; a zero value skips reclamation.
2. At `0x0018fc7a..0x0018fc87`, copy three dwords from `[EAX+0]`, `[EAX+4]`,
   and `[EAX+8]` to `[[ebp-4]+0]`, `[[ebp-4]+4]`, and `[[ebp-4]+8]`.
3. At `0x0018fc8a..0x0018fc97`, call `0x0016b84c` with the copied-from pointer
   and absolute zone/global value `[0x001f7ae4]`.

The export labels `0x0016b84c` `_zfree`; its raw prologue reads the two pushed
arguments at `[ebp+8]` and `[ebp+0xc]`.  Therefore the direct byte-supported
claim is that the original pointer loaded from `[[ebp-4]]` is passed as the
first argument to the `_zfree`-labelled target *after* its first 12 bytes were
copied into the cursor location.  This is evidence of unlink/replacement before
the reclamation call.  It does not establish the C type or allocation history
of that pointer.

The function reaches `0x0018fd17` after the list ends, pushes the saved value
`[ebp-0x14]`, then calls `0x0018b544` at `0x0018fd1b`.  Thus all normal
in-range list iterations have completed their per-entry lock release before the
single saved-priority restoration call.  The out-of-range early return bypasses
both the initial priority raise and that final restoration.

## Findings relevant to open item 2

* PV removal now has a raw-byte verified node lifetime boundary: three-dword
  replacement/unlink, then a direct call to the `_zfree`-labelled target with
  the original pointer and `[0x001f7ae4]`.
* Per-entry exclusion is raw-byte verified at offset `+0x0c`, and is released
  before advancing to the next entry.
* The whole routine saves the return from its `_splvm`-labelled entry call and
  supplies that value to its `_splx`-labelled exit call only on the in-range
  path.

## Limits

This does not infer C structs, semantic ownership, the exact pmap record type,
or the meaning of `FUN_00190f90`.  Those require additional original-byte
control/data-flow evidence.
