#!/usr/bin/env bash
# vm-sparc.sh install|boot [--qemu62] [--cd ISO|KEY] [--snapshot] [--gdb-wait] [--serial] [-- QEMU args]
#   install  boots the CD (-boot d); OpenBIOS starts the OPENSTEP booter by itself
#   boot     boots the hard disk (-boot c)
# SPARCstation 5 with QEMU's OpenBIOS: this QEMU with a real Sun PROM (OBP 2.22,
# ss5.bin) dies with "Trap 0x29 ... Error state" once the kernel starts (QEMU
# issue 2620); with OpenBIOS the kernel reaches the installer.  1024x768x8:
# cg3 for install, default TCX for boot.  CD SCSI 6 with 512-byte blocks; HDD qcow2 writethrough at SCSI 3
# for install, SCSI 0 for boot.
# Pinned to one host core: the sun4m ESP/DMA emulation can hang under heavy
# disk I/O on several cores.  Default: GTK window, terminal = QEMU monitor.
# --serial: -nographic -serial mon:stdio (Ctrl-A x quits).
# --qemu62: run Ubuntu's QEMU 6.2 (1:6.2+dfsg-2ubuntu6.31) instead of this build.
#   With this build the installer's second phase hangs in a kernel spinlock
#   (SPARC_INSTALL_HANG_NOTES.md); the install is done with 6.2.  Its OpenBIOS,
#   FCode ROMs and GTK module come from the host's qemu-system-data and
#   qemu-system-gui 6.2 packages.
source "$(dirname -- "${BASH_SOURCE[0]}")/vm-common.sh"
qemu62=0 args=()
while [[ $# -gt 0 ]]; do
    case "$1" in --qemu62) qemu62=1; shift ;; --) args+=("$@"); break ;; *) args+=("$1"); shift ;; esac
done
vm_parse 'install|boot' "${args[@]}"
qemu="$bin_dir/qemu-system-sparc"
if [[ $qemu62 == 1 ]]; then
    qemu="$emu_dir/qemu-6.2-ubuntu/qemu-system-sparc"
    want=1760627db220087cb5a2e15ec18f0547d4d92eba8aa1c0987579b16630ee7ea3
    [[ -x "$qemu" && "$(sha256sum < "$qemu" | cut -d' ' -f1)" == "$want" ]] ||
        { echo "$qemu missing or not the pinned QEMU 6.2 binary" >&2; exit 1; }
fi
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
ui_args=(-display gtk -monitor stdio); [[ $serial == 1 ]] && ui_args=(-nographic -serial mon:stdio)
vm_banner sparc; echo "QEMU $("$qemu" --version | head -n 1)"
exec taskset -c 0 "$qemu" -name "OPENSTEP sparc ($mode)" \
    -M SS-5 -m 64 "${vga[@]}" -g 1024x768x8 -rtc base=utc,clock=host -boot "$boot" \
    -drive "file=$disk,format=qcow2,if=none,id=hd,cache=writethrough" -device scsi-hd,drive=hd,scsi-id=$hd_id,lun=0 \
    -drive "if=none,id=cd,file=$iso,format=raw,media=cdrom,readonly=on" \
    -device scsi-cd,channel=0,scsi-id=6,drive=cd,logical_block_size=512,physical_block_size=512 \
    "${ui_args[@]}" "${debug_args[@]}" "${snap_args[@]}" "${extra[@]}"
