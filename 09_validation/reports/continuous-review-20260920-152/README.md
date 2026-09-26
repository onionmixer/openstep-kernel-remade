# `_smmap` indirect callback table — `_cdevsw` static image와 runtime writers

## Correction

The earlier working assumption that `0x001e2f58` was BSS and that its selector
stride was 60 bytes was wrong.  Original Mach-O/nlist evidence identifies
`0x001e2f38` as file-backed `__DATA` symbol `_cdevsw`; `0x001e2f58` is its
`+0x20` slot.  This report supersedes that assumption without modifying prior
preserved reports.

## Static layout and `_smmap` dispatch

Python calculated `0x001e369c - 0x001e2f38 = 1,892` bytes.  The raw static
`_nchrdev` dword at `0x001e369c` is 43, and `1,892 / 43 = 44` bytes with zero
remainder.  Thus the static table has 43 entries (indices 0–42), each 11
dwords/44 bytes.  SHA-256 of exactly those table bytes is
`0d398b44bdf627c559d627beb3b66d801b7076305232879ed75f00eddebbf62d`.

At `_smmap`:

```
0x00106f5b  MOVZX EAX,BYTE PTR [EAX+0x43]
0x00106f5f  LEA EDX,[EAX+EAX*4]      ; 5*selector
0x00106f62  LEA EDX,[EAX+EDX*2]      ; 11*selector
0x00106f65  MOV ESI,[EDX*4+0x1e2f58] ; cdevsw + 44*selector + 0x20
0x00106fae  CALL ESI
```

Before `CALL ESI`, the function rejects `ESI == 0x0010ccb0`,
`ESI == 0x0010cca4`, and zero.  The export labels those first two addresses
`_nulldev` and `_nodev`; the comparisons themselves are the raw evidence.
Python decoded all 43 static `+0x20` slot values: every one is `0x0010cca4`.
Therefore no static table entry reaches the indirect call in this image.

## Runtime writer boundaries

The exact table range has 35 direct/SIB accesses in export bodies and zero
writers when only an absolute table displacement is considered.  That filter
cannot see indexed destinations constructed from the base, so the raw
base-materialization audit is decisive:

* `_IOAddToCdevswAt` (`0x001a9c6c`) calculates `index * 44 + 0x001e2f38`.
  On its successful path it writes 11 dwords to offsets `0x00` through `0x28`;
  the `+0x20` callback slot is written at `0x001a9d12` from `[ebp+0x2c]`.
  With index `-1` it searches entries bounded by `[0x001e369c]` against the
  44-byte default template at `0x001e5100`.
* `_IOAddToCdevsw` (`0x001a9d30`) performs the analogous search and the same
  11 dword writes, including slot `+0x20` at `0x001a9dce`.
* `_IORemoveFromCdevsw` (`0x001a9dec`) calculates the same indexed destination
  and uses `REP MOVSD` with `ECX=11` to copy the default template from
  `0x001e5100` over the entry.
* `_sd_init_idmap` materializes the base only to scan it in 44-byte steps; its
  shown cdevsw instructions are reads.

The export's direct unconditional calls to the two writer functions are:
`0x001a453e -> _IOAddToCdevswAt` and
`0x001a46b9 -> _IORemoveFromCdevsw`.  No direct exported call targets
`_IOAddToCdevsw` in the reference inventory.

## Finding for open item 1

The `_smmap` callback table is now tied to an original-byte verified static
table, actual dispatch slot, static sentinel contents, and three runtime
overwrite/restore mechanisms.  This resolves the address-table identity that
the earlier exact-displacement scan left unnamed.

## Limit

This does not prove which runtime call supplies a particular callback value,
whether a selected byte is bounded before `_smmap`, or any target's semantic
type.  It also cannot exclude a writer that receives an already-derived entry
pointer without materializing `_cdevsw` in its own body.
