
/* WARNING: Removing unreachable block (ram,0xf00cb964) */
/* WARNING: Removing unreachable block (ram,0xf00cb93c) */
/* WARNING: Removing unreachable block (ram,0xf00cb8fc) */
/* WARNING: Removing unreachable block (ram,0xf00cb920) */
/* WARNING: Removing unreachable block (ram,0xf00cb950) */
/* WARNING: Removing unreachable block (ram,0xf00cb97c) */
/* WARNING: Removing unreachable block (ram,0xf00cb8f0) */

undefined8 -[IOEthernet performLoopback:](uint param_1,undefined4 param_2,byte *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
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
  pbVar1 = param_3;
  _nb_map();
  pbVar2 = param_3;
  _nb_size(param_3);
  if (((*pbVar1 & 1) != 0) &&
     (uVar3 = param_1, _objc_msgSend(param_1,paIsunwantedmult,pbVar1), (uVar3 & 0xff) == 0)) {
    uVar3 = param_1;
    _objc_msgSend(param_1,paAllocatenetbuf);
    if (uVar3 != 0) {
      _nb_map(param_3);
      _nb_write(uVar3,0,pbVar2 + 0xe,param_3);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x14c),paHandleinputpac,uVar3,0);
    }
  }
  return CONCAT44(param_2,param_1);
}

