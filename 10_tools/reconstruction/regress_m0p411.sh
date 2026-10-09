#!/bin/bash
# plan 411 regression: run the x86 consumers of macho_obj/l1_compare and keep every output in $1
set -u
O=$1; mkdir -p $O; export PYTHONDONTWRITEBYTECODE=1
T=10_tools/reconstruction
R=08_build/runs
python3 $T/test_l1_compare.py $R/s1b-t1-kernel-4/out --report $O/t_l1_compare.json > $O/t_l1_compare.log 2>&1; echo "t_l1_compare $?" >> $O/rc
python3 $T/test_l1_abs.py > $O/t_l1_abs.log 2>&1; echo "t_l1_abs $?" >> $O/rc
python3 $T/test_objc_compare.py $R/s1d-tobjc-1/out --report $O/t_objc.json > $O/t_objc.log 2>&1; echo "t_objc $?" >> $O/rc
python3 $T/test_objc_nomethod.py 03_original/x86/binaries/mach_kernel $R/s6l4-g2ba/out/L2_359__generalFuncsPrivate.o > $O/t_nomethod.log 2>&1; echo "t_nomethod $?" >> $O/rc
python3 $T/test_zerofill_l1place.py 03_original/x86/binaries/mach_kernel 03_original/x86/inventory/symbols.tsv 09_validation/reconstruction/zerofill-known-s5p394-20261008.json $R/s6l4-g2ba/out/L2_360__IOVPCodeDisplay.o $R/s6l4-g1a/out/L2_358__generalFuncs.o > $O/t_zerofill.log 2>&1; echo "t_zerofill $?" >> $O/rc
python3 -c "
import json,glob
for f in sorted(glob.glob('09_validation/reconstruction/s6-l1-G*-s6l4-*.json')):
  for o in json.load(open(f))['objects']: print(o['obj'])" > $O/objs.txt
python3 $T/check_macho_obj.py $(cat $O/objs.txt) > $O/check_macho_obj.log 2>&1; echo "check_macho_obj $?" >> $O/rc
python3 $T/m0_slice_l1.py selftest $O/m0self $O/m0self-summary.json > $O/m0self.log 2>&1; echo "m0self $?" >> $O/rc
python3 $T/m1_version_diff.py selftest $O/m1self.json $O/m1work > $O/m1self.log 2>&1; echo "m1self $?" >> $O/rc
python3 $T/m1_version_diff.py run $O/m1run.json $O/m1run > $O/m1run.log 2>&1; echo "m1run $?" >> $O/rc
python3 $T/l2_place.py $O/l2_place.json > $O/l2_place.log 2>&1; echo "l2_place $?" >> $O/rc
python3 $T/l2_place.py $O/l2_place_self.json --selftest > $O/l2_place_self.log 2>&1; echo "l2_place_self $?" >> $O/rc
python3 $T/l2_coverage.py $O/l2_cov.json > $O/l2_cov.log 2>&1; echo "l2_cov $?" >> $O/rc
L2_COVER=s6l1 python3 $T/l2_coverage.py $O/l2_cov_s6l1.json > $O/l2_cov_s6l1.log 2>&1; echo "l2_cov_s6l1 $?" >> $O/rc
echo DONE >> $O/rc
