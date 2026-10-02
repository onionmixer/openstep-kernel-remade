#!/usr/bin/env bash
# vm-i386.sh install|boot|boot-nocd [--cd ISO] [--snapshot] [--gdb-wait] [-- QEMU args]
#   install    CD boot from the OPENSTEP_BOOTCD ISO (phase 1). The installer's
#              reboot ends QEMU (-no-reboot); then run "boot".
#   boot       hard-disk boot with the CD still attached (phase 2 reads packages from it)
#   boot-nocd  hard-disk boot without the CD
#   --cd ISO|KEY  boot mode only: another CD (path or site.conf key, e.g.
#              OS42_DEV_ISO) in the same IDE position.
# Layout: HDD = IDE primary master, CD = IDE secondary master.
# Terminal = QEMU monitor. See 11_emulation/QEMU_VM_CONFIGURATIONS.md section 3.
source "$(dirname -- "${BASH_SOURCE[0]}")/vm-common.sh"
vm_parse 'install|boot|boot-nocd' "$@"
[[ -z $cd_file || $mode == boot ]] || { echo "--cd is only for boot mode" >&2; exit 2; }
vm_disk i386; vm_sockets i386
cd_args=()
if [[ $mode != boot-nocd ]]; then
    iso="$(vm_cd OPENSTEP_BOOTCD_ISO)"
    cd_args=(-drive "file=$iso,if=ide,index=2,media=cdrom,format=raw,readonly=on")
fi
boot=c; [[ $mode == install ]] && boot=d
vm_banner i386; [[ ${#cd_args[@]} -gt 0 ]] && echo "CD   $iso"
exec "$bin_dir/qemu-system-i386" -name "OPENSTEP i386 ($mode)" \
    -nodefaults -M pc -cpu pentium3 -m 64 -vga cirrus -no-reboot -boot "$boot" \
    -drive "file=$disk,if=ide,index=0,media=disk,format=raw" "${cd_args[@]}" \
    -display gtk -monitor stdio "${debug_args[@]}" "${snap_args[@]}" "${extra[@]}"
