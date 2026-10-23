#!/usr/bin/env bash
# build-qemu-sparcstep.sh -- out-of-tree build of 11_emulation/qemu-sparcstep
# (jadenekotenshi/qemu, branch sparcstep) for the SPARC VM only.
#
#   bash 11_emulation/scripts/build-qemu-sparcstep.sh
#
# The clone is never modified and configure never runs inside it.  The script
# refuses to run unless HEAD is the pinned commit and the working tree is clean,
# and checks both again afterwards.  i386 and m68k keep build/qemu-NeXT-lab
# (build-qemu.sh).
set -euo pipefail
here="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
src="$here/qemu-sparcstep"
out="$here/build/qemu-sparcstep"
py="$here/build/py-sparcstep"
want_head=a6abc3b5b0fe47da87ee5ab45bcaa156f4223f2b

check_src() {
    local head dirty
    head=$(git -C "$src" rev-parse HEAD)
    dirty=$(git -C "$src" status --porcelain | wc -l)
    if [[ "$head" != "$want_head" || "$dirty" != 0 ]]; then
        echo "source state changed: HEAD=$head, $dirty changed paths" >&2
        exit 1
    fi
    echo "source OK: HEAD=$head, clean"
}

check_src
# configure needs Python >= 3.12 and installs its "tooling" group
# (pythondeps.toml: pip >= 23.2.1, wheel >= 0.41.2, setuptools >= 63.1.0).  This host's system Python
# is 3.10; the base is uv's CPython 3.12.12, and a private venv with pinned
# pip/wheel from PyPI is given to --python.
pybase="$HOME/.local/share/uv/python/cpython-3.12.12-linux-x86_64-gnu/bin/python3.12"
want_pybase=4304de9fdcd8465bbf4bf0814bb7abadd6d33971bab26ae38d1080c355fec983
[[ "$(sha256sum < "$(readlink -f "$pybase")" | cut -d' ' -f1)" == "$want_pybase" ]] ||
    { echo "$pybase missing or not the pinned CPython 3.12.12" >&2; exit 1; }
if [[ ! -x "$py/bin/python3" ]]; then
    "$pybase" -m venv "$py"
    "$py/bin/python3" -m pip install --disable-pip-version-check pip==24.3.1 wheel==0.45.1 setuptools==75.8.0
fi
"$py/bin/python3" -m pip --version
"$py/bin/python3" -c 'import wheel, setuptools; print("wheel", wheel.__version__, "setuptools", setuptools.__version__)'
# Subprojects: qemu-NeXT already has keycodemapdb and the Berkeley float
# libraries at the revisions this tree's wraps pin; copy them instead of
# downloading.  These directories are in the clone's subprojects/.gitignore.
for w in keycodemapdb berkeley-softfloat-3 berkeley-testfloat-3; do
    [[ -d "$src/subprojects/$w" ]] && continue
    rev=$(sed -n 's/^revision = //p' "$src/subprojects/$w.wrap")
    have=$(git -C "$here/qemu-NeXT/subprojects/$w" rev-parse HEAD)
    [[ "$have" == "$rev" ]] || { echo "$w: qemu-NeXT has $have, wrap wants $rev" >&2; exit 1; }
    if [[ -d "$src/subprojects/packagefiles/$w" ]]; then
        diff -r "$src/subprojects/packagefiles/$w" "$here/qemu-NeXT/subprojects/packagefiles/$w" >/dev/null ||
            { echo "$w: packagefiles differ from qemu-NeXT's" >&2; exit 1; }
    fi
    cp -a "$here/qemu-NeXT/subprojects/$w" "$src/subprojects/$w"
done
check_src
mkdir -p "$out"
cd "$out"
if [[ ! -f config.status ]]; then
    "$src/configure" --python="$py/bin/python3" \
        --target-list=sparc-softmmu \
        --enable-gtk --enable-slirp --disable-docs --disable-werror \
        --disable-download --disable-fdt --disable-rust
fi
ninja -j"$(nproc)" qemu-system-sparc qemu-img
# The VNC keymap is only generated when qemu-keymap could be built.
if ninja -t targets all | grep -q '^pc-bios/keymaps/en-us:'; then
    ninja pc-bios/keymaps/en-us
fi
check_src
for b in qemu-system-sparc qemu-img; do
    sha256sum "$out/$b"
    "$out/$b" --version | head -1
done
