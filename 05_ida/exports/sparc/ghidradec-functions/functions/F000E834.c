
/* WARNING: Removing unreachable block (ram,0xf000e890) */
/* WARNING: Removing unreachable block (ram,0xf000e874) */
/* WARNING: Removing unreachable block (ram,0xf000e8ac) */
/* WARNING: Removing unreachable block (ram,0xf000e838) */

undefined8 _leavepgrp(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = (int)*(sword *)(param_1 + 0x30);
  _get_posix_proc();
  iVar3 = *(int *)(*(int *)(iVar1 + 0x10) + 4);
  piVar4 = (int *)(*(int *)(iVar1 + 0x10) + 4);
  do {
    if (iVar3 == 0) {
      _panic(aLeavepgrpCanTF);
loc_F000E898:
      if (*(int *)(*(int *)(iVar1 + 0x10) + 4) == 0) {
        _pgdelete(*(int *)(iVar1 + 0x10));
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      *(undefined2 *)(param_1 + 0x2e) = 0;
      return CONCAT44(param_2,param_1);
    }
    if (*piVar4 == param_1) {
      *piVar4 = *(int *)(iVar1 + 0xc);
      goto loc_F000E898;
    }
    iVar2 = (int)*(sword *)(*piVar4 + 0x30);
    _get_posix_proc();
    iVar3 = *(int *)(iVar2 + 0xc);
    piVar4 = (int *)(iVar2 + 0xc);
  } while( true );
}
