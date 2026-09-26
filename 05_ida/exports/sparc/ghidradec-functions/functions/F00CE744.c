
/* WARNING: Removing unreachable block (ram,0xf00ce808) */
/* WARNING: Removing unreachable block (ram,0xf00ce7e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce794) */
/* WARNING: Removing unreachable block (ram,0xf00ce7b8) */
/* WARNING: Removing unreachable block (ram,0xf00ce7f8) */
/* WARNING: Removing unreachable block (ram,0xf00ce818) */
/* WARNING: Removing unreachable block (ram,0xf00ce754) */

undefined8 -[SCSIDisk free](undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined7 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 7;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  iVar5 = 0;
  if (0 < (int)param_1[99]) {
    do {
      _objc_msgSend(param_1,paEnqueuesdbuf,puVar2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)param_1[99]);
  }
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  if ((param_1[0x62] & 0x8000) != 0) {
    _objc_msgSend(param_1[0x61],paReleasetargetL,*(undefined *)(param_1 + 0x62),
                  *(undefined *)((int)param_1 + 0x189),param_1);
  }
  uVar1 = paFree;
  _objc_msgSend(param_1[0x6e],paFree);
  *(undefined4 **)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = &aIodisk;
  _objc_getOrigClass();
  *(undefined7 **)((int)register0x00000038 + -0xc) = puVar3;
  puVar4 = (undefined *)((int)register0x00000038 + -0x10);
  _objc_msgSendSuper(puVar4,uVar1);
  return CONCAT44(param_2,puVar4);
}
