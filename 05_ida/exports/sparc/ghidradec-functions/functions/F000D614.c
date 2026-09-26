
/* WARNING: Removing unreachable block (ram,0xf000d6a8) */
/* WARNING: Removing unreachable block (ram,0xf000d618) */

undefined8 _init_process(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  int iVar3;
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
  _suser();
  if (param_1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar3 = *_active_u;
    if (*(int *)(iVar3 + 0x4c) == 0) {
      iVar1 = *(int *)(iVar3 + 0x50);
    }
    else {
      *(undefined4 *)(*(int *)(iVar3 + 0x4c) + 0x50) = *(undefined4 *)(iVar3 + 0x50);
      iVar1 = *(int *)(iVar3 + 0x50);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(iVar3 + 0x44);
    }
    else {
      *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(iVar3 + 0x4c);
      iVar1 = *(int *)(iVar3 + 0x44);
    }
    if (*(int *)(iVar1 + 0x48) == iVar3) {
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar3 + 0x4c);
      *(int *)(iVar3 + 0x44) = iVar3;
    }
    else {
      *(int *)(iVar3 + 0x44) = iVar3;
    }
    *(undefined4 *)(iVar3 + 0x4c) = 0;
    *(undefined4 *)(iVar3 + 0x50) = 0;
    if ((int)*(sword *)(iVar3 + 0x30) != (int)*(sword *)(iVar3 + 0x2e)) {
      _enterpgrp(iVar3,(int)*(sword *)(iVar3 + 0x30),0);
    }
    *(undefined2 *)(iVar3 + 0x32) = 0;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
