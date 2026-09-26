
/* WARNING: Removing unreachable block (ram,0xf00ccd9c) */
/* WARNING: Removing unreachable block (ram,0xf00ccd80) */
/* WARNING: Removing unreachable block (ram,0xf00cce54) */
/* WARNING: Removing unreachable block (ram,0xf00cce18) */
/* WARNING: Removing unreachable block (ram,0xf00ccdfc) */
/* WARNING: Removing unreachable block (ram,0xf00cce04) */
/* WARNING: Removing unreachable block (ram,0xf00cce38) */
/* WARNING: Removing unreachable block (ram,0xf00cce60) */
/* WARNING: Removing unreachable block (ram,0xf00ccd8c) */
/* WARNING: Removing unreachable block (ram,0xf00cce68) */
/* WARNING: Removing unreachable block (ram,0xf00ccd5c) */
/* WARNING: Removing unreachable block (ram,0xf00ccd4c) */

undefined8
-[IOTokenRing outputPacket:address:](int param_1,undefined4 param_2,byte *param_3,int param_4)

{
  undefined (*pauVar1) [10];
  byte *pbVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (*(int *)(param_1 + 0x128) < 0) {
    pbVar2 = param_3;
    _nb_size();
    if (*(byte **)(param_1 + 0x138) < pbVar2) {
      _objc_msgSend(param_1,paName);
      pbVar2 = param_3;
      _nb_size(param_3);
      _IOLog(aSNetoutputBadF,param_1,pbVar2);
    }
    else {
      uVar3 = 0;
      if (((*(byte *)(param_4 + 8) & 0x80) != 0) &&
         ((uVar3 = *(byte *)(param_4 + 0xe) & 0x1f, (*(byte *)(param_4 + 0xe) & 1) != 0 ||
          (0x10 < uVar3 - 2)))) {
        uVar3 = 0xffffffff;
      }
      uVar4 = uVar3 + 0xe;
      if ((int)uVar3 < 0) {
        uVar4 = uVar3;
      }
      if (-1 < (int)uVar4) {
        _nb_grow_top(param_3,uVar4);
        pbVar2 = param_3;
        _nb_map();
        _bcopy(param_4,pbVar2,uVar4);
        pauVar1 = paTransmit;
        *pbVar2 = *pbVar2 & 0xf0;
        _objc_msgSend(param_1,pauVar1,param_3);
        uVar5 = 0;
        goto locret_F00CCE74;
      }
      _objc_msgSend(param_1,paName);
      _IOLog(aSBadMacHeader,param_1);
    }
    _nb_free(param_3);
    uVar5 = 0x28;
  }
  else {
    _nb_free(param_3);
    uVar5 = 0x32;
  }
locret_F00CCE74:
  return CONCAT44(param_2,uVar5);
}
