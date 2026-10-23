#!/usr/bin/env bash
# vm-sparc.sh install|boot [--lab|--qemu62] [--cd ISO|KEY] [--disk QCOW2 --snapshot] [--snapshot]
#             [--gdb-wait] [--serial|--vnc SOCK] [-- QEMU args]
#   install  boots the CD (-boot d); OpenBIOS starts the OPENSTEP booter by itself
#   boot     boots the hard disk (-boot c)
# Emulator (2026-10-23): build/qemu-sparcstep, jadenekotenshi/qemu branch
# sparcstep (build-qemu-sparcstep.sh), whose sparc32-espdma delays the ESP
# interrupt (esp-irq-delay-ns, 200 us) for the OPENSTEP kernel's SCSI lock race
# (SPARC_INSTALL_HANG_NOTES.md).
# --lab: the earlier build/qemu-NeXT-lab (QEMU 11.0.90).  Its installer's second
#   phase hangs in a kernel spinlock.
# --qemu62: Ubuntu's QEMU 6.2 (1:6.2+dfsg-2ubuntu6.31), used for the 2026-09-30
#   install.  Its OpenBIOS, FCode ROMs and GTK module come from the host's
#   qemu-system-data and qemu-system-gui 6.2 packages.
# SPARCstation 5 with QEMU's OpenBIOS: a real Sun PROM (OBP 2.22, ss5.bin) made
# QEMU 11.0.90 die with "Trap 0x29 ... Error state" once the kernel started
# (QEMU issue 2620).  1024x768x8: cg3 for install, default TCX for boot.  CD
# SCSI 6 with 512-byte blocks; HDD qcow2 writethrough at SCSI 3 for install,
# SCSI 0 for boot.
# Pinned to one host core: the sun4m ESP/DMA emulation could hang under heavy
# disk I/O on several cores.  Default: GTK window, terminal = QEMU monitor.
# --serial: -nographic -serial mon:stdio (Ctrl-A x quits).
# --vnc SOCK: no local window, VNC on the unix socket SOCK, no monitor (use QMP).
# --disk QCOW2 (boot, with --snapshot): boot a copy of the SPARC disk instead.
source "$(dirname -- "${BASH_SOURCE[0]}")/vm-common.sh"
qemu62=0 lab=0 vnc_sock="" args=()
while [[ $# -gt 0 ]]; do
    case "$1" in
        --qemu62) qemu62=1; shift ;;
        --lab) lab=1; shift ;;
        --vnc) [[ $# -ge 2 ]] || vm_usage 'install|boot'; vnc_sock="$2"; shift 2 ;;
        --) args+=("$@"); break ;;
        *) args+=("$1"); shift ;;
    esac
done
[[ $qemu62 == 1 && $lab == 1 ]] && { echo "--lab and --qemu62 are exclusive" >&2; exit 2; }
vm_parse 'install|boot' "${args[@]}"
[[ -n $vnc_sock && $serial == 1 ]] && { echo "--vnc and --serial are exclusive" >&2; exit 2; }
qemu="$emu_dir/build/qemu-sparcstep/qemu-system-sparc"
want=d64a3948524cda028a29f5177420b8910ae988e46abccaaf97bbcb3fca7259d1
what="the pinned sparcstep build (build-qemu-sparcstep.sh)"
if [[ $lab == 1 ]]; then
    qemu="$bin_dir/qemu-system-sparc"
    want=fe991d20750bba3b5f8713f794364ef982a3f816b6162f2d3e43797ecee795f8
    what="the pinned qemu-NeXT-lab build"
elif [[ $qemu62 == 1 ]]; then
    qemu="$emu_dir/qemu-6.2-ubuntu/qemu-system-sparc"
    want=1760627db220087cb5a2e15ec18f0547d4d92eba8aa1c0987579b16630ee7ea3
    what="the pinned QEMU 6.2 binary"
fi
[[ -x "$qemu" && "$(sha256sum < "$qemu" | cut -d' ' -f1)" == "$want" ]] ||
    { echo "$qemu missing or not $what" >&2; exit 1; }
vm_disk sparc qcow2; vm_sockets sparc
iso="$(vm_cd OS42_SPARC_ISO)"            # boot --cd: another CD at the same SCSI ID
# Install with the disk at SCSI 3; boot the installed system with it at SCSI 0
# (the -hda position): OpenBIOS's "disk" boot finds nothing at SCSI 3 (QEMU
# issue 2620 installs at unit 3, then boots with -hda).
# Display: cg3 for the installer; the installed system's Window Server has a
# driver for the default TCX (8-bit), not cg3 ("No Display drivers loaded!").
boot=c hd_id=0 vga=(); [[ $mode == install ]] && { boot=d; hd_id=3; vga=(-vga cg3); }
# -qmp turns off the default monitor, which also un-muxes -nographic's serial
# console; mon:stdio keeps serial + monitor muxed (Ctrl-A x quits, Ctrl-A c monitor).
# -display none stops the OPENSTEP booter (Unhandled Exception 0x21); VNC alone works.
ui_args=(-display gtk -monitor stdio)
[[ $serial == 1 ]] && ui_args=(-nographic -serial mon:stdio)
# VNC needs keymaps/en-us; these builds have no qemu-keymap, so a directory
# holding only the host qemu-system-data copy is added (firmware search unchanged).
if [[ -n $vnc_sock ]]; then
    ui_args=(-display "vnc=unix:$vnc_sock" -monitor none)
    km="$emu_dir/build/sparcstep-keymaps"
    [[ $qemu62 == 1 ]] || { [[ -r $km/keymaps/en-us ]] || { echo "missing $km/keymaps/en-us" >&2; exit 1; }; ui_args+=(-L "$km"); }
fi
vm_banner sparc; echo "QEMU $("$qemu" --version | head -n 1)"
exec taskset -c 0 "$qemu" -name "OPENSTEP sparc ($mode)" \
    -M SS-5 -m 64 "${vga[@]}" -g 1024x768x8 -rtc base=utc,clock=host -boot "$boot" \
    -drive "file=$disk,format=qcow2,if=none,id=hd,cache=writethrough" -device scsi-hd,drive=hd,scsi-id=$hd_id,lun=0 \
    -drive "if=none,id=cd,file=$iso,format=raw,media=cdrom,readonly=on" \
    -device scsi-cd,channel=0,scsi-id=6,drive=cd,logical_block_size=512,physical_block_size=512 \
    "${ui_args[@]}" "${debug_args[@]}" "${snap_args[@]}" "${extra[@]}"
