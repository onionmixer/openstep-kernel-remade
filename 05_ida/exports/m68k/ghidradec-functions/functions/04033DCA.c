
undefined8 _blkpref(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  iVar6 = *(int *)(iVar1 + 0x5c);
  uVar3 = param_3 / iVar6;
  if ((param_3 % iVar6 != 0) && (iVar2 = *(int *)(param_4 + -4 + param_3 * 4), iVar2 != 0)) {
    iVar2 = *(int *)(iVar1 + 0x38) + iVar2;
    iVar6 = *(int *)(iVar1 + 0x58);
    if ((param_3 <= iVar6) ||
       (uVar3 = param_3 - iVar6,
       iVar2 == *(int *)(param_4 + uVar3 * 4) + (iVar6 << (*(uint *)(iVar1 + 0x60) & 0x3f)))) {
      uVar3 = 0;
      if (*(int *)(iVar1 + 0x40) != 0) {
        iVar6 = *(int *)(iVar1 + 0x38);
        uVar3 = iVar6 * (((*(int *)(iVar1 + 0xa8) * *(int *)(iVar1 + 0x44) * *(int *)(iVar1 + 0x40))
                          / (*(int *)(iVar1 + 0x7c) * 1000) + -1 + iVar6) / iVar6);
        iVar2 = uVar3 + iVar2;
      }
    }
    goto loc_4033F22;
  }
  if (0xb < param_2) {
    if ((param_3 == 0) || (iVar2 = *(int *)(param_4 + -4 + param_3 * 4), iVar2 == 0)) {
      iVar6 = param_2 / iVar6 + *(uint *)(param_1 + 0x46) / *(uint *)(iVar1 + 0xb8);
    }
    else {
      iVar6 = iVar2 / *(int *)(iVar1 + 0xbc) + 1;
    }
    uVar3 = *(uint *)(iVar1 + 0x2c);
    uVar5 = iVar6 % (int)uVar3;
    iVar6 = *(int *)(iVar1 + 0xc4) / (int)uVar3;
    if ((int)uVar5 < (int)uVar3) {
      uVar4 = uVar5;
      do {
        if (iVar6 <= *(int *)(*(int *)(iVar1 + ((int)uVar4 >> (*(uint *)(iVar1 + 0x70) & 0x3f)) * 4
                                      + 0x2d8) + 4 + (~*(uint *)(iVar1 + 0x6c) & uVar4) * 0x10))
        goto loc_4033ECE;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < (int)uVar3);
    }
    uVar4 = 0;
    if (-1 < (int)uVar5) {
      uVar3 = ~*(uint *)(iVar1 + 0x6c);
      do {
        if (iVar6 <= *(int *)(*(int *)(iVar1 + ((int)uVar4 >> (*(uint *)(iVar1 + 0x70) & 0x3f)) * 4
                                      + 0x2d8) + 4 + (uVar3 & uVar4) * 0x10)) goto loc_4033ECE;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 <= (int)uVar5);
    }
    iVar2 = 0;
    goto loc_4033F22;
  }
  uVar4 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar1 + 0xb8);
loc_4033ED2:
  iVar2 = *(int *)(iVar1 + 0x38) + uVar4 * *(int *)(iVar1 + 0xbc);
loc_4033F22:
  return CONCAT44(iVar2,uVar3);
loc_4033ECE:
  *(uint *)(iVar1 + 0x2d4) = uVar4;
  goto loc_4033ED2;
}
