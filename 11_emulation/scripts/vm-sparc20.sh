#!/usr/bin/env bash
# vm-sparc20.sh boot [--snapshot] [--cd ISO|KEY] [--disk RAW --snapshot] [--gdb-wait]
#                    [--vnc SOCK] [--no-pin] [-- QEMU args]
# SPARCstation 20 with a real Sun PROM (2026-10-24, user's command; plan in
# 02_plan/EMULATION_PLATFORM_PLAN.md): -M SS-20 -smp 1 -m 448, -bios PROM,
# cg14 1152x900x24, a raw installed disk at SCSI 3 (SUN SUN2.1G), the NVRAM
# file as -drive if=mtd, a lance NIC on user networking, an empty CD at SCSI 6.
# Only build/qemu-sparcstep has cg14 (the lab and 6.2 builds do not).
# Media come from 11_emulation/site.conf: SS20_PROM, SS20_DISK (raw),
# SS20_NVRAM (0 or 8192 bytes), SS20_MAC (optional, default 08:00:20:C0:FF:EE).
# Without --snapshot QEMU writes the disk and the NVRAM file: at every start it
# rewrites the NVRAM ID PROM (0x1fd8-) from the MAC and machine, and fills an
# all-zero NVRAM with defaults (hw/sparc/sun4m.c nvram_init), even with -S.
# --snapshot: nothing is written (all -drive writes go to temporary overlays).
# --disk RAW (with --snapshot only): boot a copy of the disk, e.g. one holding a
#   reconstructed kernel; the configured disk is not opened.
# --cd ISO|KEY: put a CD in the empty drive (path or site.conf key).
# --vnc SOCK: no SDL window, VNC on the unix socket SOCK, no monitor (use QMP).
# --no-pin: do not pin to host core 0 (pinning is the vm-sparc.sh convention for
#   the ESP/DMA race, SPARC_INSTALL_HANG_NOTES.md; it is not a proven cure).
# cg14 has no depth property: x24 picks the monitor size, the guest sets depth.
source "$(dirname -- "${BASH_SOURCE[0]}")/vm-common.sh"
vnc_sock="" pin=1 args=()
while [[ $# -gt 0 ]]; do
    case "$1" in
        --vnc) [[ $# -ge 2 ]] || vm_usage boot; vnc_sock="$2"; shift 2 ;;
        --no-pin) pin=0; shift ;;
        --) args+=("$@"); break ;;
        *) args+=("$1"); shift ;;
    esac
done
vm_parse boot "${args[@]}"
[[ $serial == 1 ]] && { echo "--serial is not supported here (cg14 console; use --vnc)" >&2; exit 2; }
qemu="$emu_dir/build/qemu-sparcstep/qemu-system-sparc"
want=d64a3948524cda028a29f5177420b8910ae988e46abccaaf97bbcb3fca7259d1
[[ -x "$qemu" && "$(sha256sum < "$qemu" | cut -d' ' -f1)" == "$want" ]] ||
    { echo "$qemu missing or not the pinned sparcstep build (build-qemu-sparcstep.sh)" >&2; exit 1; }

# site.conf value that is not a file (vm_media requires a readable file)
site_value() { [[ -r "$site_conf" ]] && sed -n "s/^$1=//p" "$site_conf" | tail -n 1; }
# a value inside a QEMU -drive option: commas are doubled
qopt() { printf '%s' "${1//,/,,}"; }

prom="$(readlink -f -- "$(vm_media SS20_PROM)")"
[[ -f $prom ]] || { echo "SS20_PROM: not a regular file: $prom" >&2; exit 1; }
if [[ -n $disk_file ]]; then
    [[ $snapshot == 1 ]] || { echo "--disk needs --snapshot (the test disk is never written)" >&2; exit 2; }
    disk="$(readlink -f -- "$disk_file")"
else
    disk="$(readlink -f -- "$(vm_media SS20_DISK)")"
fi
python3 -c 'import os,sys
p=sys.argv[1]
ok=os.path.isfile(p) and os.access(p,os.R_OK) and os.path.getsize(p)>0 and os.path.getsize(p)%512==0
sys.exit(0 if ok and open(p,"rb").read(4)!=b"QFI\xfb" else 1)' "$disk" ||
    { echo "disk: needs a readable non-empty raw image whose size is a multiple of 512: $disk" >&2; exit 1; }
nvram="$(readlink -f -- "$(vm_media SS20_NVRAM)")"
python3 -c 'import os,sys
p=sys.argv[1]
sys.exit(0 if os.path.isfile(p) and os.path.getsize(p) in (0, 8192) else 1)' "$nvram" ||
    { echo "SS20_NVRAM: needs a regular file of 0 or 8192 bytes (m48t08): $nvram" >&2; exit 1; }
if [[ $snapshot == 0 ]]; then
    [[ -w $disk && -w $nvram ]] || { echo "without --snapshot the disk and the NVRAM file must be writable" >&2; exit 1; }
fi
mac="$(site_value SS20_MAC)"; mac="${mac:-08:00:20:C0:FF:EE}"
[[ $mac =~ ^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$ ]] || { echo "SS20_MAC: not a MAC address: $mac" >&2; exit 1; }
cd_opt=""
if [[ -n $cd_file ]]; then
    cdpath="$(readlink -f -- "$(vm_cd OS42_SPARC_ISO)")"
    cd_opt=",file=$(qopt "$cdpath")"
fi
vm_sockets sparc20
snap_args=(); [[ $snapshot == 1 ]] && snap_args=(-snapshot)

# -qmp turns off the default monitor; SDL keeps the monitor on this terminal.
ui_args=(-display sdl -monitor stdio)
if [[ -n $vnc_sock ]]; then
    km="$emu_dir/build/sparcstep-keymaps"
    [[ -r $km/keymaps/en-us ]] || { echo "missing $km/keymaps/en-us" >&2; exit 1; }
    ui_args=(-display "vnc=unix:$vnc_sock" -monitor none -L "$km")
fi
cmd=("$qemu" -name "OPENSTEP sparc SS-20 (boot)"
    -M SS-20 -smp 1 -m 448 -bios "$prom" -vga cg14 -g 1152x900x24
    -drive "file=$(qopt "$disk"),if=none,id=disk0,format=raw"
    -device scsi-hd,scsi-id=3,drive=disk0,vendor=SUN,product=SUN2.1G,removable=off,dpofua=off
    -drive "file=$(qopt "$nvram"),if=mtd,format=raw"
    -net "nic,model=lance,macaddr=$mac,netdev=net0" -netdev user,id=net0
    -drive "if=none,id=cd0,media=cdrom,readonly=on$cd_opt" -device scsi-cd,scsi-id=6,drive=cd0
    "${ui_args[@]}" "${debug_args[@]}" "${snap_args[@]}" "${extra[@]}")
[[ $pin == 1 ]] && cmd=(taskset -c 0 "${cmd[@]}")

echo "VM sparc SS-20  mode=$mode$([[ $snapshot == 1 ]] && echo '  (snapshot: disk and NVRAM not written)')"
[[ $snapshot == 0 ]] && echo "NOTE: the disk and the NVRAM file will be written (NVRAM ID PROM at every start)"
for f in "$prom" "$disk" "$nvram" ${cdpath:+"$cdpath"}; do
    printf '%-6s %12s  %s  %s\n' media "$(stat -c %s "$f")" "$(sha256sum < "$f" | cut -d' ' -f1)" "$f"
done
echo "QMP  $qmp_sock"
echo "GDB  $gdb_sock$([[ $gdb_wait == 1 ]] && echo '  (paused: attach and continue)')"
echo "QEMU $("$qemu" --version | head -n 1)"
printf 'CMD '; printf '%q ' "${cmd[@]}"; echo
exec "${cmd[@]}"
