
/* WARNING: Removing unreachable block (ram,0xf00ceb50) */
/* WARNING: Removing unreachable block (ram,0xf00ceb08) */
/* WARNING: Removing unreachable block (ram,0xf00ceaa4) */
/* WARNING: Removing unreachable block (ram,0xf00cea28) */
/* WARNING: Removing unreachable block (ram,0xf00cea54) */
/* WARNING: Removing unreachable block (ram,0xf00ceac0) */
/* WARNING: Removing unreachable block (ram,0xf00ceb40) */
/* WARNING: Removing unreachable block (ram,0xf00ceb78) */
/* WARNING: Removing unreachable block (ram,0xf00cea18) */

undefined8 -[SCSIDisk sdReadCapacity:](undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  puVar1 = (undefined4 *)param_1[0x61];
  _objc_msgSend(puVar1,paAllocatebuffer,8,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 8;
  }
  else {
    uVar5 = uVar5 + 7 & -uVar5;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 2;
  puVar3 = (undefined *)((int)register0x00000038 + -0x70);
  puVar2[5] = puVar3;
  puVar2[3] = puVar1;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar4 = paEnqueuesdbuf;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0x25;
  *(byte *)((int)register0x00000038 + -0x6b) =
       *(byte *)((int)register0x00000038 + -0x6b) & 0x1f | *(char *)((int)param_1 + 0x189) << 5;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  _objc_msgSend(param_1,uVar4);
  iVar6 = *(int *)((int)register0x00000038 + -0x50);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar6 == 0) {
    if (*(int *)((int)register0x00000038 + -0x48) == 8) {
      *param_3 = *puVar1;
      param_3[1] = puVar1[1];
      iVar6 = *(int *)((int)register0x00000038 + -0x50);
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
    else {
      iVar6 = 0x16;
      _objc_msgSend(param_1,paName);
      _IOLog(aSBadDmaTransfe_0,param_1,*(undefined4 *)((int)register0x00000038 + -0x48));
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
  }
  _IOFree(uVar4,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar6);
}
