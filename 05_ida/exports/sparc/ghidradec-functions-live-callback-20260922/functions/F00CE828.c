
/* WARNING: Removing unreachable block (ram,0xf00ce9a4) */
/* WARNING: Removing unreachable block (ram,0xf00ce9d4) */
/* WARNING: Removing unreachable block (ram,0xf00ce95c) */
/* WARNING: Removing unreachable block (ram,0xf00ce8e0) */
/* WARNING: Removing unreachable block (ram,0xf00ce864) */
/* WARNING: Removing unreachable block (ram,0xf00ce858) */
/* WARNING: Removing unreachable block (ram,0xf00ce890) */
/* WARNING: Removing unreachable block (ram,0xf00ce8fc) */
/* WARNING: Removing unreachable block (ram,0xf00ce9c4) */
/* WARNING: Removing unreachable block (ram,0xf00ce994) */
/* WARNING: Removing unreachable block (ram,0xf00ce9e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce84c) */

undefined8 -[SCSIDisk sdInquiry:](undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [14];
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar7;
  int iVar8;
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
  puVar7 = (uint *)((int)register0x00000038 + -0x6c);
  iVar2 = param_1[0x61];
  _objc_msgSend(iVar2,paAllocatebuffer,0x41,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero();
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar6 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar6 < 2) {
    uVar6 = 0x41;
  }
  else {
    uVar6 = uVar6 + 0x40 & -uVar6;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar6;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar3 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar3 = 2;
  puVar4 = (undefined *)((int)register0x00000038 + -0x70);
  puVar3[5] = puVar4;
  puVar3[3] = iVar2;
  _IOVmTaskSelf();
  puVar3[4] = puVar4;
  pauVar1 = paEnqueuesdbuf;
  *(undefined *)puVar7 = 0x12;
  *puVar7 = *puVar7 & 0xff1fffff | (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x41;
  puVar3[8] = puVar3[8] & 0x7fffffff | 0x40000000;
  _objc_msgSend(param_1,pauVar1);
  iVar8 = *(int *)((int)register0x00000038 + -0x50);
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar8 == 0) {
    uVar6 = *(uint *)((int)register0x00000038 + -0x48);
    if (uVar6 < 5) {
      iVar8 = 0x16;
      _objc_msgSend(param_1,paName);
      _IOLog(aSBadDmaTransfe,param_1,*(undefined4 *)((int)register0x00000038 + -0x48));
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
    else {
      if (0x41 - uVar6 != 0) {
        _bzero(iVar2 + uVar6,0x41 - uVar6);
      }
      _memcpy(param_3,iVar2,0x41);
      iVar8 = *(int *)((int)register0x00000038 + -0x50);
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
  }
  _IOFree(uVar5,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar8);
}

