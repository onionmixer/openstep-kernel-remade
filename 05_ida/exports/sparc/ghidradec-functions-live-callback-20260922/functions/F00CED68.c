
/* WARNING: Removing unreachable block (ram,0xf00cee64) */
/* WARNING: Removing unreachable block (ram,0xf00cedb4) */
/* WARNING: Removing unreachable block (ram,0xf00cee7c) */
/* WARNING: Removing unreachable block (ram,0xf00ced78) */

undefined8
-[SCSIDisk scsiStartStop:inhibitRetry:]
          (undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  puVar1 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  puVar1[5] = (undefined *)((int)register0x00000038 + -0x70);
  puVar1[8] = puVar1[8] & 0xbfffffff | (uint)((param_4 & 0xff) != 0) << 0x1e | 0x80000000;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0x1b;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  if (param_3 == 1) {
    *(undefined *)((int)register0x00000038 + -0x68) = 0;
loc_F00CEE50:
    uVar2 = 3;
  }
  else {
    if (param_3 < 2) {
      *(undefined *)((int)register0x00000038 + -0x68) = 1;
      goto loc_F00CEE50;
    }
    if (param_3 != 2) goto loc_F00CEE5C;
    *(undefined *)((int)register0x00000038 + -0x68) = 2;
    uVar2 = 4;
  }
  *puVar1 = uVar2;
loc_F00CEE5C:
  puVar3 = param_1;
  _objc_msgSend(param_1,paEnqueuesdbuf,puVar1);
  _objc_msgSend(param_1,paFreesdbuf,puVar1);
  return CONCAT44(param_2,puVar3);
}

