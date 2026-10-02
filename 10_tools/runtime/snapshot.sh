#!/bin/sh
# snapshot.sh <label> -- run ON the OPENSTEP i386 target (sh, not csh).
#
# Copies the three loaded segments of the running kernel from /dev/kmem
# into 09_validation/runtime/x86-live/<label>/ on the NFS share, read-only.
# Ranges are the original Mach-O segment ranges (see macho.json); the
# host proves the kmem offset = VA assumption from the __TEXT bytes.
# Raw dumps are kernel bytes plus live state: they are gitignored.
R=/ndrv/openstep-kernel-remade
T=$R/10_tools/runtime
B=$T/bin/kmemdump
if [ $# -ne 1 ]; then echo "usage: snapshot.sh <label>"; exit 2; fi
O=$R/09_validation/runtime/x86-live/$1
if [ -d $O ]; then echo "snapshot.sh: $O exists, refusing to overwrite"; exit 2; fi
if [ ! -x $B ]; then echo "snapshot.sh: $B missing, build first"; exit 2; fi
mkdir $O || exit 1
sync
( hostinfo; /usr/etc/kl_util -s; date ) > $O/context.txt 2>&1
$B 100000 da000 $O/TEXT.bin   || exit 1
$B 1da000 1e000 $O/DATA.bin   || exit 1
$B 1f8000 12000 $O/OBJC.bin   || exit 1
ls -l $O
echo SNAPSHOT_DONE $1
