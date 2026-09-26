
/* WARNING: Removing unreachable block (ram,0xf004aab0) */
/* WARNING: Removing unreachable block (ram,0xf004a9d0) */
/* WARNING: Removing unreachable block (ram,0xf004a95c) */
/* WARNING: Removing unreachable block (ram,0xf004a9ac) */
/* WARNING: Removing unreachable block (ram,0xf004a9dc) */
/* WARNING: Removing unreachable block (ram,0xf004aabc) */
/* WARNING: Removing unreachable block (ram,0xf004a8d4) */

undefined8 _mapsearch(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
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
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x2c);
  }
  else {
    rem(param_3,*(undefined4 *)(param_1 + 0xbc));
  }
  if (param_3 < 0) {
    param_3 = param_3 + 7;
  }
  param_3 = param_3 >> 3;
  iVar1 = *(int *)(param_1 + 0xbc) + 7;
  if (iVar1 < 0) {
    iVar1 = *(int *)(param_1 + 0xbc) + 0xe;
  }
  iVar8 = (iVar1 >> 3) - param_3;
  iVar5 = *(int *)(param_1 + 0x38);
  iVar1 = iVar5;
  if (iVar5 < 0) {
    iVar1 = iVar5 + 7;
  }
  iVar4 = iVar8;
  _scanc(iVar8,param_2 + param_3 + 0x3d8,*(undefined4 *)(_fragtbl + iVar5 * 4),
         1 << ((char)param_4 + ((char)iVar5 - ((byte)iVar1 & 0xf8)) + -1 & 0x1f));
  iVar8 = param_3 + iVar8;
  if (iVar4 == 0) {
    iVar8 = param_3 + 1;
    iVar5 = *(int *)(param_1 + 0x38);
    iVar1 = iVar5;
    if (iVar5 < 0) {
      iVar1 = iVar5 + 7;
    }
    iVar4 = iVar8;
    _scanc(iVar8,param_2 + 0x3d8,*(undefined4 *)(_fragtbl + iVar5 * 4),
           1 << ((char)param_4 + ((char)iVar5 - ((byte)iVar1 & 0xf8)) + -1 & 0x1f));
    if (iVar4 == 0) {
      _printf(aStartDLenDFsS,0,iVar8,param_1 + 0xd4);
      _panic(aAlloccgMapCorr);
    }
  }
  iVar8 = (iVar8 - iVar4) * 8;
  iVar1 = iVar8 + 8;
  *(int *)(param_2 + 0x2c) = iVar8;
  if (iVar8 < iVar1) {
    do {
      iVar5 = iVar8;
      if (iVar8 < 0) {
        iVar5 = iVar8 + 7;
      }
      iVar4 = 0;
      uVar7 = *(uint *)(_around + param_4 * 4);
      uVar6 = *(uint *)(_inside + param_4 * 4);
      uVar3 = *(int *)(param_1 + 0x38) - param_4;
      if (uVar3 < 0x80000000) {
        do {
          uVar2 = ((int)(uint)*(byte *)(param_2 + (iVar5 >> 3) + 0x3d8) >>
                   ((char)iVar8 + (char)(iVar5 >> 3) * -8 & 0x1fU) &
                  0xff >> (8U - (char)*(int *)(param_1 + 0x38) & 0x1f)) << 1 & uVar7;
          uVar7 = uVar7 << 1;
          if (uVar2 == uVar6) {
            iVar8 = iVar8 + iVar4;
            goto locret_F004AAC8;
          }
          iVar4 = iVar4 + 1;
          uVar6 = uVar6 << 1;
        } while (iVar4 <= (int)uVar3);
      }
      iVar8 = iVar8 + *(int *)(param_1 + 0x38);
    } while (iVar8 < iVar1);
  }
  _printf(aBnoDFsS,iVar8,param_1 + 0xd4);
  _panic(aAlloccgBlockNo);
  iVar8 = -1;
locret_F004AAC8:
  return CONCAT44(param_2,iVar8);
}

