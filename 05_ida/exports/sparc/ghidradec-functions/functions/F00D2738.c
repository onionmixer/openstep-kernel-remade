
/* WARNING: Removing unreachable block (ram,0xf00d27cc) */

undefined8
-[EventDriver registerScreen:bounds:shmem:size:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  int iVar1;
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
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    *param_5 = 0;
    *param_6 = 0;
    iVar1 = -1;
  }
  else {
    if (*(int *)(param_1 + 0x184) == 0) {
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x164);
      iVar1 = *(int *)(param_1 + 0x188);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x188);
    }
    iVar2 = *(int *)(param_1 + 0x180);
    *(undefined4 *)(iVar2 + iVar1 * 0x14) = param_3;
    iVar2 = iVar2 + iVar1 * 0x14;
    iVar1 = *(int *)(param_1 + 0x184);
    if (*(int *)(iVar2 + 8) != 0) {
      *(int *)(iVar2 + 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x184);
    }
    *(int *)(param_1 + 0x184) = iVar1 + *(int *)(iVar2 + 8);
    *param_5 = *(undefined4 *)(iVar2 + 4);
    *param_6 = *(undefined4 *)(iVar2 + 8);
    _bcopy(iVar2 + 0xc,param_4,8);
    iVar1 = *(int *)(param_1 + 0x188);
    *(int *)(param_1 + 0x188) = iVar1 + 1;
    iVar1 = iVar1 + 0x100;
  }
  return CONCAT44(param_2,iVar1);
}
