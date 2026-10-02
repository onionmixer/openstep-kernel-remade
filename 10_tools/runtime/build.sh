#!/bin/sh
# build.sh -- run ON the target: compile kmemdump with the native cc.
T=/ndrv/openstep-kernel-remade/10_tools/runtime
[ -d $T/bin ] || mkdir $T/bin
cc -O -Wall -o $T/bin/kmemdump $T/kmemdump.c || exit 1
ls -l $T/bin/kmemdump
# Refusal self-test: both must be rejected before /dev/kmem is opened.
$T/bin/kmemdump 0ff000 1000 /dev/null;  echo "below-window rc=$? (want 2)"
$T/bin/kmemdump 209000 2000 /dev/null;  echo "past-window rc=$? (want 2)"
