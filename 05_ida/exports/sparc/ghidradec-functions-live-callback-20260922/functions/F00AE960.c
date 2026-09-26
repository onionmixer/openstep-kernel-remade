
undefined8 _fpu_rightshift(uint param_1,uint param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  uint uVar3;
  undefined4 unaff_i2;
  byte bVar4;
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
  uVar2 = param_1;
  uVar3 = param_2;
  if ((int)param_2 < 0x72) {
    for (; 0x1f < (int)uVar3; uVar3 = uVar3 - 0x20) {
      *(uint *)(param_1 + 0x20) =
           *(uint *)(param_1 + 0x20) |
           *(uint *)(param_1 + 0x1c) | *(uint *)(param_1 + 0x18) & 0x7fffffff;
      uVar2 = *(uint *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x18) >> 0x1f;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
      *(uint *)(param_1 + 0x14) = uVar2;
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    param_2 = 1;
    if (0 < (int)uVar3) {
      bVar1 = (byte)uVar3;
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar3 = (1 << (bVar1 & 0x1f)) - 1;
      *(uint *)(param_1 + 0x20) =
           *(uint *)(param_1 + 0x20) |
           *(uint *)(param_1 + 0x1c) | uVar2 & (1 << (bVar1 - 1 & 0x1f)) - 1U;
      *(uint *)(param_1 + 0x1c) = (uVar2 & uVar3) >> (bVar1 - 1 & 0x1f);
      bVar4 = 0x20 - bVar1;
      *(uint *)(param_1 + 0x18) =
           (*(uint *)(param_1 + 0x14) & uVar3) << (bVar4 & 0x1f) | uVar2 >> (bVar1 & 0x1f);
      *(uint *)(param_1 + 0x14) =
           (*(uint *)(param_1 + 0x10) & uVar3) << (bVar4 & 0x1f) |
           *(uint *)(param_1 + 0x14) >> (bVar1 & 0x1f);
      uVar2 = *(uint *)(param_1 + 0x10) >> (bVar1 & 0x1f);
      param_2 = (*(uint *)(param_1 + 0xc) & uVar3) << (bVar4 & 0x1f) | uVar2;
      *(uint *)(param_1 + 0x10) = param_2;
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) >> (bVar1 & 0x1f);
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (((*(int *)(param_1 + 0xc) == 0 && *(int *)(param_1 + 0x10) == 0) && uVar2 == 0) &&
        *(int *)(param_1 + 0x18) == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 1;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return CONCAT44(param_2,uVar2);
}

