
undefined8 _timeval_to_ns_time(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  int iVar5;
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
  uVar4 = *param_1;
  iVar5 = (int)uVar4 >> 0x1f;
  iVar2 = ((uVar4 >> 0x1b | iVar5 << 5) - iVar5) - (uint)(uVar4 * 0x20 < uVar4);
  uVar3 = param_1[1];
  uVar1 = uVar4 * 1000000 + uVar3;
  iVar2 = (uVar4 * 0x3d09 >> 0x1a |
          ((uVar4 * 0x7a1 >> 0x1d |
           (((uVar4 * 0x1f >> 0x1a | iVar2 * 0x40) - iVar2) - (uint)(uVar4 * 0x7c0 < uVar4 * 0x1f))
           * 8) + iVar5 + (uint)CARRY4(uVar4 * 0x3d08,uVar4)) * 0x40) + ((int)uVar3 >> 0x1f) +
          (uint)CARRY4(uVar4 * 1000000,uVar3);
  return CONCAT44(uVar1 * 1000,
                  uVar1 * 0x7d >> 0x1d |
                  ((uVar1 * 0x1f >> 0x1e |
                   (((uVar1 >> 0x1b | iVar2 * 0x20) - iVar2) - (uint)(uVar1 * 0x20 < uVar1)) * 4) +
                   iVar2 + (uint)CARRY4(uVar1 * 0x7c,uVar1)) * 8);
}

