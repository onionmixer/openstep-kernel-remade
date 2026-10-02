# 12_archive — imported records

Only this README is tracked. Everything else under `12_archive/` is ignored by
the root `.gitignore`: it is large, private, and contains material that must
not be redistributed (OPENSTEP install disks, NeXT ROMs, decompiled OPENSTEP
userland, session transcripts).

## openstep-iso-remade/

Records of the separate OPENSTEP 4.2 Japanese ISO repair and qemu-NeXT
work, moved here on 2026-09-30 before that workspace
(`/mnt/USERS/onion/DATA_ORIGN/Workspace/openstep-iso-remade`, also reached as
`/home/onion/Workspace/openstep-iso-remade`) was retired. Plan:
[`02_plan/EMULATION_PLATFORM_PLAN.md`](../02_plan/EMULATION_PLATFORM_PLAN.md).

**These records are not kernel-analysis evidence.** They concern the install
CD, the m68k installer and QEMU device models. The kernel-analysis rules in
`AGENTS.md` still apply: nothing here is a source for statements about the
original kernel's behaviour.

| Path | What it is | How it got here |
|---|---|---|
| `PLAN_OPENSTEP_42_JAPANESE_ISO_REPAIR.md` and the other top-level files | The ISO repair plan and log, notes, screenshots | moved (same filesystem rename) |
| `tools/` | Scripts, gdb command files, Python analysis tools of that work | moved |
| `artifacts/` | m68k install disks (`qemu_next/*.raw`), NeXT ROM v66, SPARC boot analysis, Ghidra output, BOM/ditto analysis, pcaps | moved |
| `vendor/qemu-NeXT`, `vendor/previous` | Relative links to `../../../11_emulation/…`, so the old paths still resolve | created |
| `tmp-import/` | Copies of that session's `/tmp` files (`openstep-*`, `openstep_qemu_*`, `os42j*`, `qemu-next-pr-*.md`), including the SPARC OpenBoot 2.22 PROM and the QEMU 6.2 sparc package used for the SS-20 measurement | copied, SHA-256 verified |
| `claude-transcripts/` | The two Claude Code session transcripts of that workspace | copied, SHA-256 verified |
| `codex-transcripts/` | The codex session log whose working directory was that workspace | copied, SHA-256 verified |

The emulator source trees moved to [`../11_emulation/`](../11_emulation/README.md).

## Verification record

Stored in `11_emulation/records/migration-20260930/` (ignored):

- `iso-remade-inventory.json`: every entry before the move (path, type, size,
  mtime, inode, link target). After the move all 18,557 entries were found at
  their new paths with the same inode. The only differences were the mtimes
  of 22 loose git objects in qemu-NeXT, which git refreshes when it rewrites an
  existing object; all 22 re-hash to their names and `git fsck` passes.
- `tmp-import-manifest.json`: SHA-256 of all 3,216 copied `/tmp` files
  (6.43 GiB logical, sparse disk images included) and targets of the copied
  links. One entry was not copied: a stale QMP Unix socket
  (`os42j-netdiag.mPYqd9/qmp_static.sock`), which has no content.
- `transcripts.sha256`: the two Claude transcripts.

| Group | Entries | File bytes |
|---|---|---|
| moved to `12_archive/openstep-iso-remade/` | 487 | 23.05 GiB |
| moved to `11_emulation/qemu-NeXT/` | 17,639 | 0.48 GiB |
| moved to `11_emulation/previous/` | 431 | 11.2 MiB |

## Known limits

- The original ISO images and floppy images referenced by these records live
  on `/mnt/MAMEALL`. On 2026-09-30 that disk (`sdd`) returned
  `DID_BAD_TARGET` for every read; they were not copied and are not here.
- The old in-tree QEMU build (`11_emulation/qemu-NeXT/build/`) and the old
  scripts in `tools/` point at the retired absolute path. Use
  `11_emulation/scripts/` instead.
- Linked git worktrees of qemu-NeXT live under `/tmp` and vanish on reboot.
  Their branches are kept in the repository refs and in the
  `onionmixer/qemu-NeXT` fork; run `git worktree prune` after they are gone.
