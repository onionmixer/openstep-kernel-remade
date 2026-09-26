
/* WARNING: Removing unreachable block (ram,0xf000fc60) */
/* WARNING: Removing unreachable block (ram,0xf000fbb8) */
/* WARNING: Removing unreachable block (ram,0xf000fba4) */
/* WARNING: Removing unreachable block (ram,0xf000fbd8) */
/* WARNING: Removing unreachable block (ram,0xf000fca4) */
/* WARNING: Removing unreachable block (ram,0xf000fb7c) */

undefined8 _setpgid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar4 = *_active_u;
  if (piVar5[1] < 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F000FCAC;
  }
  iVar1 = (int)*(sword *)(iVar4 + 0x30);
  _get_posix_proc();
  iVar3 = *piVar5;
  if ((iVar3 == 0) || (iVar3 == *(sword *)(iVar4 + 0x30))) {
    iVar2 = *(int *)(iVar1 + 0x10);
loc_F000FC28:
    if (*(int *)(*(int *)(iVar2 + 8) + 4) != iVar4) {
      iVar3 = piVar5[1];
      if (iVar3 == 0) {
        piVar5[1] = (int)*(sword *)(iVar4 + 0x30);
      }
      else if ((iVar3 != *(sword *)(iVar4 + 0x30)) &&
              ((_pgfind(), iVar3 == 0 ||
               (*(int *)(iVar3 + 8) != *(int *)(*(int *)(iVar1 + 0x10) + 8))))) goto loc_F000FC90;
      _enterpgrp(iVar4,piVar5[1],0);
      goto locret_F000FCAC;
    }
  }
  else {
    _pfind();
    if ((iVar3 == 0) || (iVar4 = iVar3, _inferior(), iVar4 == 0)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 3;
      goto locret_F000FCAC;
    }
    iVar4 = (int)*(sword *)(iVar3 + 0x30);
    _get_posix_proc();
    if (*(int *)(*(int *)(iVar4 + 0x10) + 8) == *(int *)(*(int *)(iVar1 + 0x10) + 8)) {
      if (*(int *)(iVar3 + 0x28) < 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F000FCAC;
      }
      iVar2 = *(int *)(iVar4 + 0x10);
      iVar4 = iVar3;
      goto loc_F000FC28;
    }
  }
loc_F000FC90:
  *(undefined *)(dword_F0133DDC + 0x38) = 1;
locret_F000FCAC:
  return CONCAT44(param_2,param_1);
}

