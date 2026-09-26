
/* WARNING: Removing unreachable block (ram,0xf00cddd8) */
/* WARNING: Removing unreachable block (ram,0xf00cdd78) */
/* WARNING: Removing unreachable block (ram,0xf00cddf8) */
/* WARNING: Removing unreachable block (ram,0xf00cdd3c) */

undefined8 -[SCSIDisk updateReadyState](undefined4 *param_1,undefined4 param_2)

{
  undefined (*pauVar1) [14];
  undefined4 *puVar2;
  int iVar3;
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
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 3;
  puVar2[5] = (undefined *)((int)register0x00000038 + -0x70);
  pauVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] & 0x7fffffff | 0x40000000;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  _objc_msgSend(param_1,pauVar1,puVar2);
  iVar3 = *(int *)((int)register0x00000038 + -0x50);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,(uint)(iVar3 != 0));
}
