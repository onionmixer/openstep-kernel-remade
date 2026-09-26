
/* WARNING: Removing unreachable block (ram,0xf00d0154) */
/* WARNING: Removing unreachable block (ram,0xf00d00ec) */
/* WARNING: Removing unreachable block (ram,0xf00d0090) */
/* WARNING: Removing unreachable block (ram,0xf00d013c) */
/* WARNING: Removing unreachable block (ram,0xf00d019c) */
/* WARNING: Removing unreachable block (ram,0xf00d0080) */

undefined8 -[SCSIDisk reqSense:](int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined (*pauVar1) [30];
  undefined4 *puVar2;
  undefined (**ppauVar3) [23];
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar7;
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
  puVar2 = *(undefined4 **)(param_1 + 0x184);
  _objc_msgSend(puVar2,paAllocatebuffer,0x1c,(undefined *)((int)register0x00000038 + -0x84),
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
  pauVar1 = paExecuterequest_0;
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 0x1c;
  }
  else {
    uVar5 = uVar5 + 0x1b & -uVar5;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  uVar7 = *(undefined4 *)(param_1 + 0x184);
  ppauVar3 = &paBytesprocessed_0;
  _IOVmTaskSelf();
  _objc_msgSend(uVar7,pauVar1,(undefined *)((int)register0x00000038 + -0x70),puVar2,ppauVar3);
  *param_3 = *puVar2;
  param_3[1] = puVar2[1];
  param_3[2] = puVar2[2];
  param_3[3] = puVar2[3];
  param_3[4] = puVar2[4];
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  param_3[5] = puVar2[5];
  uVar6 = *(undefined4 *)((int)register0x00000038 + -0x88);
  param_3[6] = puVar2[6];
  _IOFree(uVar4,uVar6);
  return CONCAT44(param_2,uVar7);
}

