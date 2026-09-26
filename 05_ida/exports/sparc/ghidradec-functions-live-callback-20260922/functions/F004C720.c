
/* WARNING: Removing unreachable block (ram,0xf004c7e4) */
/* WARNING: Removing unreachable block (ram,0xf004c798) */
/* WARNING: Removing unreachable block (ram,0xf004c7d0) */
/* WARNING: Removing unreachable block (ram,0xf004c84c) */
/* WARNING: Removing unreachable block (ram,0xf004c73c) */

undefined8 sub_F004C720(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  int iVar4;
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
  iVar3 = *(int *)(param_1 + 0x50);
  iVar4 = param_1;
  _bmap(param_1,0,0,0x400,0);
  if ((iVar4 < 1) || (*(char *)(dword_F0133DDC + 0x38) != '\0')) {
    iVar4 = 0x1c;
    if (*(char *)(dword_F0133DDC + 0x38) != 0) {
      iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
  else {
    if (*(int *)(iVar3 + 0x34) < 0x400) {
      _panic(aDirblksizFsize_0);
    }
    *(undefined4 *)(param_1 + 0x70) = 0x400;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
    *(sword *)(param_2 + 0x66) = *(sword *)(param_2 + 0x66) + 1;
    *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 0x40;
    _iupdat(param_2,1);
    iVar1 = *(int *)(param_1 + 0x40);
    _bread(iVar1,iVar4 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),*(undefined4 *)(iVar3 + 0x34))
    ;
    iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    if (iVar4 == 0) {
      puVar2 = *(undefined4 **)(iVar1 + 0x20);
      *puVar2 = _mastertemplate;
      puVar2[1] = DAT_f010e9f4._0_4_;
      puVar2[2] = DAT_f010e9f4._4_4_;
      puVar2[3] = DAT_f010e9f4._8_4_;
      puVar2[4] = DAT_f010e9f4._12_4_;
      puVar2[5] = DAT_f010e9f4._16_4_;
      *puVar2 = *(undefined4 *)(param_1 + 0x48);
      puVar2[3] = *(undefined4 *)(param_2 + 0x48);
      _bwrite(iVar1);
      iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
  return CONCAT44(param_2,iVar4);
}

