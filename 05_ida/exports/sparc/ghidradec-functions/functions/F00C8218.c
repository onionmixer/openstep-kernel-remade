
/* WARNING: Removing unreachable block (ram,0xf00c82ac) */
/* WARNING: Removing unreachable block (ram,0xf00c827c) */
/* WARNING: Removing unreachable block (ram,0xf00c82bc) */
/* WARNING: Removing unreachable block (ram,0xf00c8248) */

undefined8 -[IODiskPartition checkSafeConfig:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (*(int *)(param_1 + 0x1a4) == 0) {
    uVar1 = param_1;
    _objc_msgSend(param_1,paIsanyblockdevo);
    if ((uVar1 & 0xff) == 0) {
      uVar1 = param_1;
      _objc_msgSend(param_1,paIsanyotheropen);
      if ((uVar1 & 0xff) == 0) {
        uVar3 = 0;
        goto locret_F00C82C4;
      }
      puVar2 = aSSWithOtherPar;
    }
    else {
      puVar2 = aSSWithOpenBloc;
    }
  }
  else {
    puVar2 = aSSOnPartition0;
  }
  uVar3 = 0xfffffd2b;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar2,param_1,param_3);
locret_F00C82C4:
  return CONCAT44(param_2,uVar3);
}
