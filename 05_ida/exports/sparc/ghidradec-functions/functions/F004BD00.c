
/* WARNING: Removing unreachable block (ram,0xf004bec0) */
/* WARNING: Removing unreachable block (ram,0xf004be4c) */
/* WARNING: Removing unreachable block (ram,0xf004be24) */
/* WARNING: Removing unreachable block (ram,0xf004bdec) */
/* WARNING: Removing unreachable block (ram,0xf004be44) */
/* WARNING: Removing unreachable block (ram,0xf004beb4) */
/* WARNING: Removing unreachable block (ram,0xf004bef0) */
/* WARNING: Removing unreachable block (ram,0xf004bd4c) */

undefined8
sub_F004BD00(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar4 = *(int *)((int)register0x00000038 + 0x5c);
  if ((*(int *)(param_6 + 0x30) != *(int *)(param_3 + 0x30)) ||
     (*(int *)(param_6 + 0x30) != *(int *)(param_2 + 0x30))) {
    iVar5 = 0x12;
    goto locret_F004BF08;
  }
  if (*(int *)(param_2 + 0x48) == *(int *)(param_6 + 0x48)) {
    iVar5 = -1;
    goto locret_F004BF08;
  }
  iVar5 = param_3;
  _iaccess(param_3,0x80);
  if (iVar5 != 0) goto locret_F004BF08;
  if (((*(word *)(param_3 + 100) & 0x200) == 0) ||
     (sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2), sVar1 == 0)) {
loc_F004BDB0:
    wVar2 = *(word *)(param_2 + 100);
  }
  else {
    if (sVar1 != *(sword *)(param_3 + 0x68)) {
      iVar5 = 1;
      if (*(sword *)(param_6 + 0x68) != sVar1) goto locret_F004BF08;
      goto loc_F004BDB0;
    }
    wVar2 = *(word *)(param_2 + 100);
  }
  bVar6 = (wVar2 & 0xf000) == 0x4000;
  if ((*(word *)(param_6 + 100) & 0xf000) == 0x4000) {
    if (!bVar6) {
      iVar5 = 0x15;
      goto locret_F004BF08;
    }
    iVar3 = param_6;
    sub_F004CDC4(param_6,*(undefined4 *)(param_3 + 0x48));
    iVar5 = 0x42;
    if ((iVar3 == 0) || (2 < *(sword *)(param_6 + 0x66))) goto locret_F004BF08;
  }
  else {
    iVar5 = 0x14;
    if (bVar6) goto locret_F004BF08;
  }
  _dnlc_remove(param_3 + 0xc,param_4);
  **(undefined4 **)(iVar4 + 0x10) = *(undefined4 *)(param_2 + 0x48);
  _dnlc_enter(param_3 + 0xc,param_4,param_2 + 0xc,0);
  _bwrite(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 0xc) = 0;
  iVar5 = (int)*(char *)(dword_F0133DDC + 0x38);
  if (iVar5 == 0) {
    *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x42;
    *(sword *)(param_6 + 0x66) = *(sword *)(param_6 + 0x66) + -1;
    *(word *)(param_6 + 0x44) = *(word *)(param_6 + 0x44) | 0x40;
    if (bVar6) {
      sVar1 = *(sword *)(param_6 + 0x66);
      *(sword *)(param_6 + 0x66) = sVar1 + -1;
      if (sVar1 != 1) {
        _panic(aDirenterTarget);
      }
      _itrunc(param_6,0);
      *(sword *)(param_3 + 0x66) = *(sword *)(param_3 + 0x66) + -1;
      *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x40;
      if ((param_1 != param_3) &&
         (iVar5 = param_2, sub_F004BF10(param_2,param_1,param_3), iVar5 != 0)) goto locret_F004BF08;
    }
    iVar5 = 0;
  }
locret_F004BF08:
  return CONCAT44(param_2,iVar5);
}
