
/* WARNING: Removing unreachable block (ram,0xf00cecc4) */
/* WARNING: Removing unreachable block (ram,0xf00cec50) */
/* WARNING: Removing unreachable block (ram,0xf00cebe4) */
/* WARNING: Removing unreachable block (ram,0xf00cebb8) */
/* WARNING: Removing unreachable block (ram,0xf00cec34) */
/* WARNING: Removing unreachable block (ram,0xf00ceca4) */
/* WARNING: Removing unreachable block (ram,0xf00cecd4) */
/* WARNING: Removing unreachable block (ram,0xf00ceba8) */

undefined8 -[SCSIDisk sdModeSense:](undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [14];
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  uVar2 = param_1[0x61];
  _objc_msgSend(uVar2,paAllocatebuffer,0x3c,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar6 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar6 < 2) {
    uVar6 = 0x3c;
  }
  else {
    uVar6 = uVar6 + 0x3b & -uVar6;
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
  puVar3[3] = uVar2;
  _IOVmTaskSelf();
  puVar3[4] = puVar4;
  pauVar1 = paEnqueuesdbuf;
  *(undefined *)puVar7 = 0x1a;
  *puVar7 = *puVar7 & 0xff1fffff | (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x3c;
  puVar3[8] = puVar3[8] | 0x80000000;
  _objc_msgSend(param_1,pauVar1);
  iVar8 = *(int *)((int)register0x00000038 + -0x50);
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar8 == 0) {
    _memcpy(param_3,uVar2,0x3c);
    iVar8 = *(int *)((int)register0x00000038 + -0x50);
    uVar5 = *(undefined4 *)((int)register0x00000038 + -0x84);
  }
  _IOFree(uVar5,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar8);
}

