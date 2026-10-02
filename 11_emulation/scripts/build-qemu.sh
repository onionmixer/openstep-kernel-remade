#!/usr/bin/env bash
# build-qemu.sh -- out-of-tree build of 11_emulation/qemu-NeXT for the three
# OPENSTEP targets (i386, SPARC, m68k).
#
#   bash 11_emulation/scripts/build-qemu.sh [build-name]
#
# Never run configure inside qemu-NeXT/: QEMU's configure, run from its own
# source directory, removes a configure-created ./build (configure lines 22-30).
# The source tree carries an uncommitted working-tree diff; this script refuses
# to run unless HEAD and that diff's hash are the recorded ones, and checks
# them again afterwards.
set -euo pipefail
here="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
src="$here/qemu-NeXT"
name="${1:-qemu-NeXT-lab}"
out="$here/build/$name"
want_diff=a4b401ec4e1bf8557450f0fb89c147d7a6623fee215010bb16b30fffc9117571
want_head=a69770301194d3ec4a0c08d3c253153d5f0c460a

check_src() {
    local head diff
    head=$(git -C "$src" rev-parse HEAD)
    diff=$(git -C "$src" diff | sha256sum | cut -d' ' -f1)
    if [[ "$head" != "$want_head" || "$diff" != "$want_diff" ]]; then
        echo "source state changed: HEAD=$head diff=$diff" >&2
        exit 1
    fi
    echo "source OK: HEAD=$head lab-diff=$diff"
}

check_src
mkdir -p "$out"
cd "$out"
if [[ ! -f config.status ]]; then
    "$src/configure" \
        --target-list=i386-softmmu,sparc-softmmu,m68k-softmmu \
        --enable-gtk --enable-slirp --disable-docs --disable-werror \
        --disable-download --enable-fdt=internal
fi
# OPENSTEP's automatic network setup sends NeXT-vendor BOOTP.  The system
# libslirp (4.6.1 here) answers with RFC/DHCP options and rc.net retries
# forever; the libslirp pinned by qemu-NeXT's subprojects/slirp.wrap
# (blanham/libslirp ff3ef960...) answers in NeXT format.  Force that fallback.
# libfdt: build the already-extracted subprojects/dtc (no download).
if ! grep -qx '#define CONFIG_SLIRP_PLAN9_BOOTP' config-host.h ||
   ! grep -q '^#define CONFIG_FDT' config-host.h; then
    pyvenv/bin/meson setup --reconfigure --force-fallback-for=slirp -Dfdt=internal "$out" "$src"
fi
# Build only what this project runs.  The default target also compiles the
# PowerPC device trees with whatever "dtc" is on PATH; on this host that is
# KryoFlux's /usr/bin/dtc (package kryoflux-dtc), which rejects "-q" and stops
# the build.  The firmware the three targets need is linked into
# qemu-bundle/ at configure time, so these targets are enough to run.
ninja -j"$(nproc)" qemu-system-i386 qemu-system-sparc qemu-system-m68k qemu-img
check_src
grep -qx '#define CONFIG_SLIRP_PLAN9_BOOTP' config-host.h ||
    { echo "build is not using the pinned NeXT BOOTP libslirp" >&2; exit 1; }
grep -q '^#define CONFIG_FDT' config-host.h ||
    { echo "build is not using the internal libfdt" >&2; exit 1; }
# Capture first: with pipefail, "ldd | grep -q" fails when grep exits early.
ldd_out=$(ldd "$out/qemu-system-m68k")   # absolute: a relative path yields "..././subprojects"
grep -q "=> $out/subprojects/slirp/libslirp.so" <<<"$ldd_out" ||
    { echo "qemu-system-m68k does not load the in-build libslirp" >&2; exit 1; }
echo "libslirp: pinned fallback $(git -C "$src/subprojects/slirp" rev-parse HEAD)"
for b in qemu-system-i386 qemu-system-sparc qemu-system-m68k qemu-img; do
    sha256sum "$out/$b"
    "$out/$b" --version | head -1
done
