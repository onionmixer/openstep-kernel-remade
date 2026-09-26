
/* WARNING: Removing unreachable block (ram,0xf000ea1c) */
/* WARNING: Removing unreachable block (ram,0xf000ea04) */
/* WARNING: Removing unreachable block (ram,0xf000ea7c) */
/* WARNING: Removing unreachable block (ram,0xf000e9b4) */

sqword _fixjobc(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = *(int *)(param_2 + 8);
  iVar1 = (int)*(sword *)(*(int *)(param_1 + 0x44) + 0x30);
  _get_posix_proc();
  if (*(uint *)(iVar1 + 0x10) == param_2) {
    iVar1 = *(int *)(param_1 + 0x48);
  }
  else if (*(int *)(*(uint *)(iVar1 + 0x10) + 8) == iVar4) {
    if (param_3 == 0) {
      iVar1 = *(int *)(param_2 + 0x10) + -1;
      *(int *)(param_2 + 0x10) = iVar1;
      if (iVar1 == 0) {
        sub_F000EA9C(param_2);
      }
    }
    else {
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
    iVar1 = *(int *)(param_1 + 0x48);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x48);
  }
  while (iVar1 != 0) {
    iVar2 = (int)*(sword *)(iVar1 + 0x30);
    _get_posix_proc();
    uVar3 = *(uint *)(iVar2 + 0x10);
    if (uVar3 == param_2) {
      iVar1 = *(int *)(iVar1 + 0x4c);
    }
    else if (*(int *)(uVar3 + 8) == iVar4) {
      if (*(char *)(iVar1 + 0x13) == '\x05') {
        iVar1 = *(int *)(iVar1 + 0x4c);
      }
      else {
        if (param_3 == 0) {
          iVar2 = *(int *)(uVar3 + 0x10) + -1;
          *(int *)(uVar3 + 0x10) = iVar2;
          if (iVar2 == 0) {
            sub_F000EA9C(uVar3);
          }
        }
        else {
          *(int *)(uVar3 + 0x10) = *(int *)(uVar3 + 0x10) + 1;
        }
        iVar1 = *(int *)(iVar1 + 0x4c);
      }
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x4c);
    }
  }
  return (qword)param_2 << 0x20;
}

