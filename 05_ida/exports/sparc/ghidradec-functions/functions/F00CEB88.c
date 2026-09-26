
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
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
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
  puVar6 = (uint *)((int)register0x00000038 + -0x6c);
  uVar1 = param_1[0x61];
  _objc_msgSend(uVar1,paAllocatebuffer,0x3c,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 0x3c;
  }
  else {
    uVar5 = uVar5 + 0x3b & -uVar5;
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
  puVar2[3] = uVar1;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar4 = paEnqueuesdbuf;
  *(undefined *)puVar6 = 0x1a;
  *puVar6 = *puVar6 & 0xff1fffff | (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x3c;
  puVar2[8] = puVar2[8] | 0x80000000;
  _objc_msgSend(param_1,uVar4);
  iVar7 = *(int *)((int)register0x00000038 + -0x50);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar7 == 0) {
    _memcpy(param_3,uVar1,0x3c);
    iVar7 = *(int *)((int)register0x00000038 + -0x50);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  }
  _IOFree(uVar4,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar7);
}
