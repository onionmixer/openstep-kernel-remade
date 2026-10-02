#!/usr/bin/env bash
# vm-m68k.sh install|boot [--cd ISO|KEY] [--snapshot] [--gdb-wait] [-- QEMU args]
#   install  startup floppy + CD; at the ROM "NeXT>" prompt type:  bfd
#   boot     CD + NIC + NetInfo server; at "NeXT>" type:  bsd   (single user: bsd -s)
#            Use it for phase 2 after phase 1 ends, and for the installed system.
# NeXTstation Color, 32 MiB (the fork's maximum), ROM v66, NeXT MODE SENSE
# quirks, HDD SCSI 0, CD SCSI 3 (read-only), floppy read-only.
# sysbus-fdc.fallback=288 is required: the startup floppy is 1,339,392 bytes and
# without it bfd stops with the ROM dma_bytes_moved warning.
# The terminal is the QEMU monitor.  See 11_emulation/QEMU_VM_CONFIGURATIONS.md.
source "$(dirname -- "${BASH_SOURCE[0]}")/vm-common.sh"
vm_parse 'install|boot' "$@"
# One m68k binary for every mode (build-qemu.sh output, all qemu-NeXT fixes
# including NetInfo BIND).  The hash pins the file; update it after a rebuild.
m68k_qemu="$bin_dir/qemu-system-m68k"
m68k_sha=fbb5364332539334ab407a5dca607e095643a55247bd677341b36e21575c943b
[[ "$(sha256sum "$m68k_qemu" | cut -d' ' -f1)" == "$m68k_sha" ]] ||
    { echo "$m68k_qemu is not the expected build (sha256 $m68k_sha); see build-qemu.sh" >&2; exit 1; }
grep -qx '#define CONFIG_SLIRP_PLAN9_BOOTP' "$bin_dir/config-host.h" ||
    { echo "QEMU build lacks the pinned NeXT BOOTP libslirp; rerun build-qemu.sh" >&2; exit 1; }
vm_disk m68k; vm_sockets m68k
net_args=()
iso="$(vm_cd OS42_M68K_ISO)"             # install and phase 2 read the CD; boot --cd: another CD
media_args=(-drive "if=scsi,bus=0,unit=3,media=cdrom,format=raw,file=$iso,readonly=on")
if [[ $mode == install ]]; then
    floppy="$(vm_media OS42_M68K_BOOT_FLOPPY)"
    media_args+=(-drive "if=floppy,format=raw,file=$floppy,readonly=on")
else
    net_args=(-nic user,model=next-mb8795,id=net0 -object netinfo-server,id=ni0,netdev=net0)
fi
vm_banner m68k
exec "$m68k_qemu" -name "OPENSTEP m68k ($mode)" \
    -M next-station-color -m 32M -bios "$fw_dir/next-rom-v66-Rev_2.5.bin" -audio driver=none \
    -global scsi-hd.quirk_mode_page_vendor_specific_next=on \
    -global scsi-hd.quirk_mode_page_format_device_next=on \
    -global sysbus-fdc.fallback=288 \
    -drive "if=scsi,bus=0,unit=0,media=disk,format=raw,file=$disk" "${media_args[@]}" \
    "${net_args[@]}" -display gtk -monitor stdio "${debug_args[@]}" "${snap_args[@]}" "${extra[@]}"
