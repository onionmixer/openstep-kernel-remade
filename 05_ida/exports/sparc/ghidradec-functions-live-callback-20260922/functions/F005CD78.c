
/* WARNING: Removing unreachable block (ram,0xf005cdf8) */
/* WARNING: Removing unreachable block (ram,0xf005ce5c) */

undefined8 _ipc_right_copyin_check(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar5;
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
  uVar3 = *param_3;
  switch(param_4) {
  case :
  case :
  case :
    uVar1 = 0x20000;
    break;
  case :
  case :
  case :
    if ((uVar3 & 0x100000) != 0) {
      uVar4 = 1;
      goto locret_F005CE68;
    }
    if ((uVar3 & 0x50000) == 0) {
      uVar4 = 0;
      goto locret_F005CE68;
    }
    piVar5 = (int *)param_3[1];
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *piVar5 = 0;
    if (-1 < piVar5[2]) {
      uVar4 = 1;
      if ((uVar3 & 0x400000) != 0) {
        uVar4 = 0;
      }
      goto locret_F005CE68;
    }
    uVar1 = 0x10000;
    if (param_4 == 0x12) {
      uVar1 = 0x40000;
    }
    break;
  :
    _panic(aIpcRightCopyin);
    uVar4 = 1;
    goto locret_F005CE68;
  }
  uVar4 = 1;
  if ((uVar3 & uVar1) == 0) {
    uVar4 = 0;
  }
locret_F005CE68:
  return CONCAT44(param_2,uVar4);
}

