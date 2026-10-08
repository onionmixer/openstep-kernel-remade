# 11_emulation — QEMU for the i386, SPARC and m68k kernels

VM configuration, media and GDB usage: [`QEMU_VM_CONFIGURATIONS.md`](QEMU_VM_CONFIGURATIONS.md).

Only this README, `QEMU_VM_CONFIGURATIONS.md`, `MANIFEST.json` and `scripts/`
are tracked. Everything else here is ignored by the root `.gitignore`: nested
git repositories, builds, non-redistributable ROMs, host paths and private
records.

## Layout

| Path | Tracked | Content |
|---|---|---|
| `QEMU_VM_CONFIGURATIONS.md` | yes | Current VM configuration for all three machines |
| `MANIFEST.json` | yes | Source revision, lab-diff hash, binary and firmware hashes |
| `scripts/vm-i386.sh`, `vm-sparc.sh`, `vm-m68k.sh`, `vm-common.sh` | yes | One launcher per VM |
| `scripts/build-qemu.sh` | yes | Builds the three emulators and `qemu-img` |
| `scripts/site.conf.example` | yes | Variable names for the host's media paths |
| `site.conf` | no | This host's media paths |
| `qemu-NeXT/` | no | git clone of `blanham/qemu-NeXT` (`metachicken` `a697703`) with an uncommitted working-tree diff |
| `previous/` | no | git clone of `probonopd/previous` (NeXT emulator, reference) |
| `build/qemu-NeXT-lab/` | no | The build all three VMs use |
| `qemu-6.2-ubuntu/` | no | Ubuntu's `qemu-system-sparc` 6.2 (`1:6.2+dfsg-2ubuntu6.31`), used by `vm-sparc.sh --qemu62` for the SPARC install |
| `firmware/` | no | `next-rom-v66-Rev_2.5.bin` (m68k). Sun PROMs `sun-ss20-obp-2.22-…ROM`, `sun-ss5-ss5.bin` are kept but not used: this QEMU runs SPARC with OpenBIOS |
| `records/` | no | qemu-NeXT PR notes and bodies, a backup of the working-tree diff, verification records |

## qemu-NeXT working tree

- The working tree carries an uncommitted diff (18 files, `git diff` SHA-256
  `a4b401ec4e1bf8557450f0fb89c147d7a6623fee215010bb16b30fffc9117571`). Its
  product code equals the fork's final `onionmixer/qemu-NeXT` `metachicken`
  (`992ef92`); it adds investigation-only trace code. A copy is in
  `records/qemu-NeXT-lab-a697703-a4b401ec.diff`.
- Do not run `git checkout`, `reset`, `stash` or `clean` in `qemu-NeXT/`.
- Do not run `configure` inside `qemu-NeXT/`: from its own directory QEMU's
  configure removes a configure-made `./build`.
- `qemu-NeXT/build/` is not used and must not be rebuilt; its meson setup and
  `qemu-bundle` links point at a retired absolute path.
- The six `pr/*` branches are in the local refs and on `onionmixer/qemu-NeXT`.

## Build

```sh
bash 11_emulation/scripts/build-qemu.sh
```

- Refuses to run unless `qemu-NeXT` HEAD and the diff hash are the values above,
  and checks them again afterwards.
- Uses the libslirp pinned by `qemu-NeXT/subprojects/slirp.wrap`
  (`--force-fallback-for=slirp`) and stops unless `qemu-system-m68k` loads it:
  the system libslirp answers the m68k guest's NeXT BOOTP in the wrong format.
- Builds libfdt from `qemu-NeXT/subprojects/dtc` (`--enable-fdt=internal`) with
  downloads disabled.
- Builds only the three system emulators and `qemu-img`. The default target
  would also compile PowerPC device trees with the first `dtc` on `PATH`; on this
  host that is KryoFlux's `/usr/bin/dtc`, a different program.
- `qemu-bundle/` links point at `qemu-NeXT/pc-bios/` by absolute path; if this
  directory moves, rebuild. A rebuild changes the binary hashes, so update the
  m68k hash in `vm-m68k.sh` and the tables in `QEMU_VM_CONFIGURATIONS.md`.

## Run

```sh
bash 11_emulation/scripts/vm-i386.sh  install|boot|boot-nocd [--cd ISO|KEY] [--disk RAW --snapshot] [--snapshot] [--gdb-wait] [-- QEMU args]
bash 11_emulation/scripts/vm-sparc.sh install|boot [--qemu62] [--cd ISO|KEY] [--snapshot] [--gdb-wait] [--serial] [-- QEMU args]
bash 11_emulation/scripts/vm-m68k.sh  install|boot [--cd ISO|KEY] [--snapshot] [--gdb-wait] [-- QEMU args]
```

Copy `scripts/site.conf.example` to `11_emulation/site.conf` and set the media
paths first. `--cd` (boot mode only) puts another CD in the machine's CD
position; it takes a path or a `site.conf` key such as `OS42_DEV_ISO`.
`--disk RAW` (i386 `boot`/`boot-nocd`, only together with `--snapshot`) boots a
raw test disk image instead of `09_validation/images/i386/openstep42-i386-hdd.raw`;
the image is never written (plan 405).
