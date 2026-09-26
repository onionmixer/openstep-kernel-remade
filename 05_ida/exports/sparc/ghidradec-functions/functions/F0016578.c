
undefined8 _ttysetspec(int *param_1)

{
  byte bVar1;
  int iVar2;
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
  uint uVar4;
  undefined4 unaff_i2;
  int iVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  uint uVar7;
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
  iVar5 = *param_1;
  uVar4 = 0;
  uVar7 = param_1[4];
  uVar6 = *(uint *)(iVar5 + 0x3c);
  iVar2 = iVar5;
  do {
    *(undefined4 *)(iVar2 + 100) = 0;
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar4 < 8);
  if ((uVar6 & 0x20) != 0) goto locret_F00168C4;
  if ((uVar7 & 0x10) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x5a);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x58);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x58) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar7 & 8) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x4f);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x50);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x55);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x55) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar7 & 0x4000000) != 0) {
    bVar1 = *(byte *)(iVar5 + 0x52);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x51);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x51) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar6 & 0x10) == 0) {
    if ((uVar7 & 0x3000000) != 0) {
      uVar3 = *(uint *)(iVar5 + 100);
      goto loc_F0016760;
    }
  }
  else {
    uVar3 = *(uint *)(iVar5 + 100);
loc_F0016760:
    *(uint *)(iVar5 + 100) = uVar3 | 0x2000;
  }
  if ((uVar7 & 0x800000) != 0) {
    *(uint *)(iVar5 + 100) = *(uint *)(iVar5 + 100) | 0x400;
  }
  if ((uVar6 & 2) == 0) {
    bVar1 = *(byte *)(iVar5 + 0x4d);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x4e);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    bVar1 = *(byte *)(iVar5 + 0x59);
    if (bVar1 != 0xff) {
      iVar2 = (uint)(bVar1 >> 5) * 4 + iVar5;
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | 1 << (bVar1 & 0x1f);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x57);
    param_1 = (int *)(uint)(*(byte *)(iVar5 + 0x57) >> 5);
    if (uVar4 != 0xff) {
      param_1 = (int *)((int)param_1 * 4 + iVar5);
      uVar4 = uVar4 & 0x1f;
      param_1[0x19] = param_1[0x19] | 1 << (sbyte)uVar4;
    }
  }
  if ((uVar6 & 4) != 0) {
    uVar4 = 0;
    do {
      uVar6 = uVar4 >> 3;
      bVar1 = (byte)uVar4;
      uVar4 = uVar4 + 1;
      iVar2 = (uVar6 & 0x1c) + iVar5;
      param_1 = (int *)(1 << (bVar1 & 0x1f));
      *(uint *)(iVar2 + 100) = *(uint *)(iVar2 + 100) | (uint)param_1;
    } while ((int)uVar4 < 0x80);
  }
  if ((uVar7 & 0x181000) == 0x101000) {
    *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) | 0x80000000;
  }
locret_F00168C4:
  return CONCAT44(uVar4,param_1);
}
