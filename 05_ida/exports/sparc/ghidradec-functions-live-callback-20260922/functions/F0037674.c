
/* WARNING: Removing unreachable block (ram,0xf00376d8) */
/* WARNING: Removing unreachable block (ram,0xf00376c0) */
/* WARNING: Removing unreachable block (ram,0xf00376cc) */

undefined8 _tcp_notify(int param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x1c);
  sVar1 = *(sword *)(iVar2 + 0x56);
  if (*(sword *)(iVar2 + 6) == 4) {
    iVar2 = *(int *)(param_1 + 0x20);
loc_F00376B8:
    *(sword *)(iVar2 + 0x6a) = sVar1;
    _wakeup(*(int *)(param_1 + 0x1c) + 0x54);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x24);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x3c);
  }
  else {
    if ((sVar1 != 0x41) && (sVar1 != 0x33)) {
      if (sVar1 != 0x40) {
        iVar2 = *(int *)(param_1 + 0x20);
        goto loc_F00376B8;
      }
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    *(undefined2 *)(iVar2 + 0x56) = 0;
  }
  return CONCAT44(param_2,param_1);
}

