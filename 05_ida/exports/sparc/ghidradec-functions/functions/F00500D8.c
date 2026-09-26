
undefined8 _fragacct(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar8;
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
  iVar3 = *(int *)(param_1 + 0x38);
  iVar6 = 1;
  bVar1 = *(byte *)(*(int *)(_fragtbl + iVar3 * 4) + param_2);
  iVar7 = param_1;
  if (1 < iVar3) {
    iVar7 = 4;
    do {
      iVar4 = iVar3;
      if (iVar3 < 0) {
        iVar4 = iVar3 + 7;
      }
      bVar2 = (byte)iVar6;
      if (((int)((uint)bVar1 << 1) >> (bVar2 + ((char)iVar3 - ((byte)iVar4 & 0xf8)) & 0x1f) & 1U) ==
          0) {
        iVar3 = *(int *)(param_1 + 0x38);
      }
      else {
        uVar8 = *(uint *)(_around + iVar7);
        uVar5 = *(uint *)(_inside + iVar7);
        iVar4 = iVar6;
        if (iVar6 <= iVar3) {
          do {
            if ((param_2 << 1 & uVar8) == uVar5) {
              iVar4 = iVar4 + iVar6;
              uVar8 = uVar8 << (bVar2 & 0x1f);
              uVar5 = uVar5 << (bVar2 & 0x1f);
              *(int *)(param_3 + iVar7) = *(int *)(param_3 + iVar7) + param_4;
            }
            uVar8 = uVar8 << 1;
            iVar4 = iVar4 + 1;
            uVar5 = uVar5 << 1;
          } while (iVar4 <= *(int *)(param_1 + 0x38));
        }
        iVar3 = *(int *)(param_1 + 0x38);
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar6 < iVar3);
  }
  return CONCAT44(param_2 << 1,iVar7);
}
