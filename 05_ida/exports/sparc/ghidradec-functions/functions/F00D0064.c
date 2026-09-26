
/* WARNING: Removing unreachable block (ram,0xf00d0154) */
/* WARNING: Removing unreachable block (ram,0xf00d00ec) */
/* WARNING: Removing unreachable block (ram,0xf00d0090) */
/* WARNING: Removing unreachable block (ram,0xf00d013c) */
/* WARNING: Removing unreachable block (ram,0xf00d019c) */
/* WARNING: Removing unreachable block (ram,0xf00d0080) */

undefined8 -[SCSIDisk reqSense:](int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined (**ppauVar2) [23];
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  puVar1 = *(undefined4 **)(param_1 + 0x184);
  _objc_msgSend(puVar1,paAllocatebuffer,0x1c,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x6c) = 3;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)(param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x1c;
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x188);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)(param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x184),paGetdmaalignmen,
                (undefined *)((int)register0x00000038 + -0x80));
  uVar3 = paExecuterequest_0;
  uVar4 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar4 < 2) {
    uVar4 = 0x1c;
  }
  else {
    uVar4 = uVar4 + 0x1b & -uVar4;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar4;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  uVar6 = *(undefined4 *)(param_1 + 0x184);
  ppauVar2 = &paBytesprocessed_0;
  _IOVmTaskSelf();
  _objc_msgSend(uVar6,uVar3,(undefined *)((int)register0x00000038 + -0x70),puVar1,ppauVar2);
  *param_3 = *puVar1;
  param_3[1] = puVar1[1];
  param_3[2] = puVar1[2];
  param_3[3] = puVar1[3];
  param_3[4] = puVar1[4];
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x84);
  param_3[5] = puVar1[5];
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x88);
  param_3[6] = puVar1[6];
  _IOFree(uVar3,uVar5);
  return CONCAT44(param_2,uVar6);
}
