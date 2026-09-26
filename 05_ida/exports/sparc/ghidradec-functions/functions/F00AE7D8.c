
undefined8 _fpu_normalize(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
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
  int iVar4;
  byte bVar5;
  undefined4 unaff_i3;
  byte bVar6;
  undefined4 unaff_i4;
  uint uVar7;
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
  uVar8 = *(uint *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = *(uint *)(param_1 + 0x18);
  if (*(int *)(param_1 + 4) != 1) goto locret_F00AE958;
  uVar7 = *(uint *)(param_1 + 0x10);
  if (((uVar8 == 0 && *(uint *)(param_1 + 0x10) == 0) && uVar2 == 0) && uVar3 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
    goto locret_F00AE958;
  }
  while (uVar1 = uVar7, uVar8 == 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
    uVar7 = uVar2;
    uVar2 = uVar3;
    uVar3 = 0;
    uVar8 = uVar1;
  }
  param_2 = uVar8 >> 1;
  if (uVar8 < 0x20000) {
    if (uVar8 < 0x10000) {
      iVar4 = 1;
      param_2 = uVar8;
      while (param_2 = param_2 * 2, param_2 < 0x10000) {
        iVar4 = iVar4 + 1;
      }
      bVar5 = (byte)iVar4;
      bVar6 = 0x20 - bVar5;
      uVar7 = -1 << (bVar6 & 0x1f);
      uVar8 = uVar8 << (bVar5 & 0x1f) | (uVar1 & uVar7) >> (bVar6 & 0x1f);
      uVar1 = uVar1 << (bVar5 & 0x1f) | (uVar2 & uVar7) >> (bVar6 & 0x1f);
      uVar2 = uVar2 << (bVar5 & 0x1f) | (uVar3 & uVar7) >> (bVar6 & 0x1f);
      uVar3 = uVar3 << (bVar5 & 0x1f);
      iVar4 = *(int *)(param_1 + 8) - iVar4;
      goto loc_F00AE944;
    }
    *(uint *)(param_1 + 0xc) = uVar8;
  }
  else {
    iVar4 = 1;
    for (; 0x1ffff < param_2; param_2 = param_2 >> 1) {
      iVar4 = iVar4 + 1;
    }
    bVar5 = (byte)iVar4;
    uVar7 = (1 << (bVar5 & 0x1f)) - 1;
    bVar6 = 0x20 - bVar5;
    uVar3 = (uVar2 & uVar7) << (bVar6 & 0x1f) | uVar3 >> (bVar5 & 0x1f);
    uVar2 = (uVar1 & uVar7) << (bVar6 & 0x1f) | uVar2 >> (bVar5 & 0x1f);
    uVar1 = (uVar8 & uVar7) << (bVar6 & 0x1f) | uVar1 >> (bVar5 & 0x1f);
    iVar4 = *(int *)(param_1 + 8) + iVar4;
    uVar8 = param_2;
loc_F00AE944:
    *(int *)(param_1 + 8) = iVar4;
    *(uint *)(param_1 + 0xc) = uVar8;
  }
  *(uint *)(param_1 + 0x10) = uVar1;
  *(uint *)(param_1 + 0x14) = uVar2;
  *(uint *)(param_1 + 0x18) = uVar3;
locret_F00AE958:
  return CONCAT44(param_2,param_1);
}
