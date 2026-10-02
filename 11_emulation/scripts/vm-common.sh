# vm-common.sh -- sourced by vm-<arch>.sh.  One VM per script: fixed disk,
# fixed debug sockets, media paths from 11_emulation/site.conf.
set -euo pipefail
emu_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
repo_dir="$(cd -- "$emu_dir/.." && pwd)"
bin_dir="$emu_dir/build/qemu-NeXT-lab"
fw_dir="$emu_dir/firmware"
site_conf="$emu_dir/site.conf"

vm_usage() { echo "usage: $(basename "$0") $1 [--cd ISO|SITE_KEY] [--snapshot] [--gdb-wait] [--serial] [-- QEMU args]" >&2; exit 2; }

# vm_parse MODES ARGS... : sets mode, snapshot, gdb_wait, serial, cd_file, extra
vm_parse() {
    local modes="$1"; shift
    mode="${1:-}"; [[ -n "$mode" ]] || vm_usage "$modes"
    [[ " ${modes//|/ } " == *" $mode "* ]] || vm_usage "$modes"
    shift
    snapshot=0 gdb_wait=0 serial=0 cd_file="" extra=()
    while [[ $# -gt 0 ]]; do
        case "$1" in
            --snapshot) snapshot=1; shift ;;   # keep the disk untouched (-snapshot)
            --gdb-wait) gdb_wait=1; shift ;;   # start paused (-S) until GDB continues
            --serial)   serial=1; shift ;;
            --cd)       [[ $# -ge 2 ]] || vm_usage "$modes"   # boot mode: another CD in the same drive
                        cd_file="$2"; shift 2 ;;
            --) shift; extra=("$@"); break ;;
            *) vm_usage "$modes" ;;
        esac
    done
}

# vm_media VAR : value of VAR from site.conf, which must name a readable file
vm_media() {
    local var="$1" val=""
    [[ -r "$site_conf" ]] || { echo "missing $site_conf (copy scripts/site.conf.example)" >&2; exit 1; }
    val="$(sed -n "s/^$var=//p" "$site_conf" | tail -n 1)"
    [[ -n "$val" ]] || { echo "$var is not set in $site_conf" >&2; exit 1; }
    [[ -r "$val" ]] || { echo "$var: cannot read $val" >&2; exit 1; }
    printf '%s\n' "$val"
}

# vm_cd DEFAULT_KEY : the CD image for this run.  --cd takes a path or a
# site.conf key (e.g. OS42_DEV_ISO); only boot mode may replace the CD.
vm_cd() {
    if [[ -z $cd_file ]]; then vm_media "$1"; return; fi
    [[ $mode == boot ]] || { echo "--cd is only for boot mode" >&2; exit 2; }
    if [[ $cd_file =~ ^[A-Z0-9_]+$ ]]; then vm_media "$cd_file"; return; fi
    [[ -r $cd_file ]] || { echo "--cd: cannot read $cd_file" >&2; exit 1; }
    printf '%s\n' "$cd_file"
}

# vm_sockets ARCH : QMP and GDB sockets; refuse if a VM already answers there
vm_sockets() {
    qmp_sock="/tmp/kr-$1-qmp.sock"; gdb_sock="/tmp/kr-$1-gdb.sock"
    local s
    for s in "$qmp_sock" "$gdb_sock"; do
        [[ -e "$s" ]] || continue
        if python3 -c 'import socket,sys; s=socket.socket(socket.AF_UNIX); s.settimeout(1); s.connect(sys.argv[1])' "$s" 2>/dev/null; then
            echo "a VM is already running on $s -- refusing to start a second one" >&2; exit 1
        fi
        rm -f "$s"                           # stale file from a VM that has exited
    done
    debug_args=(-qmp "unix:$qmp_sock,server=on,wait=off"
                -chardev "socket,path=$gdb_sock,server=on,wait=off,id=gdb0" -gdb chardev:gdb0)
    [[ $gdb_wait == 1 ]] && debug_args+=(-S)
    return 0
}

# vm_disk ARCH [FORMAT] : the VM's disk, 09_validation/images/ARCH/openstep42-ARCH-hdd.FORMAT (raw by default)
vm_disk() {
    disk_format="${2:-raw}"
    disk="$repo_dir/09_validation/images/$1/openstep42-$1-hdd.$disk_format"
    [[ -w "$disk" ]] || { echo "missing disk $disk (qemu-img create -f $disk_format ... 1G)" >&2; exit 1; }
    snap_args=(); [[ $snapshot == 1 ]] && snap_args=(-snapshot)
    return 0
}

vm_banner() {
    echo "VM $1  mode=$mode  disk=$disk$([[ $snapshot == 1 ]] && echo ' (snapshot, not written)')"
    echo "QMP  $qmp_sock"
    echo "GDB  $gdb_sock$([[ $gdb_wait == 1 ]] && echo '  (paused: attach and continue)')"
}
