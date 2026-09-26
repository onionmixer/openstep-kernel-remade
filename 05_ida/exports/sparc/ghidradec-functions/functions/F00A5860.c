
/* WARNING: Removing unreachable block (ram,0xf00a5970) */
/* WARNING: Removing unreachable block (ram,0xf00a5870) */
/* WARNING: Removing unreachable block (ram,0xf00a5a04) */

undefined8 _get_tod(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  puVar7 = *(undefined4 **)((int)register0x00000038 + 0x40);
  _pmap_change_prot(0xfefffff8,7);
  *(byte *)((int)register0x00000038 + -0x17) =
       (bRamfefffff9 & 0xf) + (char)((bRamfefffff9 & 0x7f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x16) =
       (bRamfefffffa & 0xf) + (char)((bRamfefffffa & 0x7f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x15) =
       (bRamfefffffb & 0xf) + (char)((bRamfefffffb & 0x3f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x14) = bRamfefffffc & 7;
  *(byte *)((int)register0x00000038 + -0x13) =
       (bRamfefffffd & 0xf) + (char)((bRamfefffffd & 0x3f) >> 4) * '\n';
  bRamfefffff8 = bRamfefffff8 & 0xbf;
  *(byte *)((int)register0x00000038 + -0x12) =
       (bRamfefffffe & 0xf) + (char)((bRamfefffffe & 0x1f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x11) = (bRamfeffffff & 0xf) + (bRamfeffffff >> 4) * '\n';
  _pmap_change_prot(0xfefffff8,1);
  iVar6 = 0;
  if ((((*(byte *)((int)register0x00000038 + -0x12) == 0) ||
       (0xc < *(byte *)((int)register0x00000038 + -0x12))) ||
      (*(byte *)((int)register0x00000038 + -0x13) == 0)) ||
     (((0x1f < *(byte *)((int)register0x00000038 + -0x13) ||
       (0x3b < *(byte *)((int)register0x00000038 + -0x16))) ||
      ((0x3b < *(byte *)((int)register0x00000038 + -0x17) ||
       (*(byte *)((int)register0x00000038 + -0x11) < 2)))))) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    *puVar7 = 0;
  }
  else {
    iVar4 = 2;
    if (2 < *(byte *)((int)register0x00000038 + -0x11)) {
      iVar6 = 0x1e13380;
      iVar4 = 3;
    }
    iVar3 = 1;
    bVar1 = *(byte *)((int)register0x00000038 + -0x13);
    if (1 < *(byte *)((int)register0x00000038 + -0x12)) {
      iVar5 = 4;
      do {
        if (iVar4 == 0) {
          iVar2 = 0x263b80;
          if (iVar3 != 2) {
            iVar2 = *(int *)((int)&_clk_state + iVar5);
          }
        }
        else {
          iVar2 = *(int *)((int)&_clk_state + iVar5);
        }
        iVar6 = iVar6 + iVar2;
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar3 < (int)(uint)*(byte *)((int)register0x00000038 + -0x12));
      bVar1 = *(byte *)((int)register0x00000038 + -0x13);
    }
    iVar6 = iVar6 + (bVar1 - 1) * 0x15180 + (uint)*(byte *)((int)register0x00000038 + -0x15) * 0xe10
            + (uint)*(byte *)((int)register0x00000038 + -0x16) * 0x3c +
            (uint)*(byte *)((int)register0x00000038 + -0x17);
    if (iVar6 < 0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
    else {
      *(int *)((int)register0x00000038 + -0x10) = iVar6;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    *puVar7 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  puVar7[1] = *(undefined4 *)((int)register0x00000038 + -0xc);
  return CONCAT44(param_2,puVar7);
}
