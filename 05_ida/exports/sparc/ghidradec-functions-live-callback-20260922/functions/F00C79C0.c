
/* WARNING: Removing unreachable block (ram,0xf00c7a54) */
/* WARNING: Removing unreachable block (ram,0xf00c7a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c79e8) */
/* WARNING: Removing unreachable block (ram,0xf00c7a04) */
/* WARNING: Removing unreachable block (ram,0xf00c7a3c) */
/* WARNING: Removing unreachable block (ram,0xf00c7a64) */
/* WARNING: Removing unreachable block (ram,0xf00c79cc) */

undefined8 -[IODiskPartition eject](uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar2 = param_1;
  _objc_msgSend(param_1,paChecksafeconfi,&aEject);
  if (uVar2 == 0) {
    _objc_msgSend(param_1,paFreepartitions);
    *(undefined *)(param_1 + 0x1a8) = 0;
    *(uint *)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141f38;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetformattedin,0);
    uVar2 = uVar1;
    _objc_msgSend(uVar1,paNeedsmanualpol);
    if ((uVar2 & 0xff) != 0) {
      _vol_check_manual_poll();
    }
    _objc_msgSend(uVar1,paEjectphysical);
    uVar2 = uVar1;
  }
  return CONCAT44(param_2,uVar2);
}

