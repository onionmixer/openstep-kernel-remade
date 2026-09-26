
/* WARNING: Removing unreachable block (ram,0xf00cc56c) */
/* WARNING: Removing unreachable block (ram,0xf00cc708) */
/* WARNING: Removing unreachable block (ram,0xf00cc6bc) */
/* WARNING: Removing unreachable block (ram,0xf00cc668) */
/* WARNING: Removing unreachable block (ram,0xf00cc644) */
/* WARNING: Removing unreachable block (ram,0xf00cc614) */
/* WARNING: Removing unreachable block (ram,0xf00cc5e8) */
/* WARNING: Removing unreachable block (ram,0xf00cc5a8) */
/* WARNING: Removing unreachable block (ram,0xf00cc598) */
/* WARNING: Removing unreachable block (ram,0xf00cc5c8) */
/* WARNING: Removing unreachable block (ram,0xf00cc5f4) */
/* WARNING: Removing unreachable block (ram,0xf00cc630) */
/* WARNING: Removing unreachable block (ram,0xf00cc658) */
/* WARNING: Removing unreachable block (ram,0xf00cc6a4) */
/* WARNING: Removing unreachable block (ram,0xf00cc6cc) */
/* WARNING: Removing unreachable block (ram,0xf00cc558) */
/* WARNING: Removing unreachable block (ram,0xf00cc57c) */
/* WARNING: Removing unreachable block (ram,0xf00cc534) */

undefined8 -[IOTokenRing _getInstanceTable:](int param_1,undefined4 param_2,int param_3)

{
  undefined (*pauVar1) [19];
  undefined (*pauVar2) [12];
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  _objc_msgSend(param_3,paConfigtable_0);
  if (param_3 == 0) {
    iVar3 = param_1;
    _objc_msgSend(param_1,paName);
    _objc_msgSend(param_1,paUnit_0);
    _IOLog(aSCouldnTGetIns,iVar3,param_1);
    uVar6 = 1;
  }
  else {
    iVar3 = param_3;
    _objc_msgSend(param_3,paValueforstring,aRingSpeed);
    iVar4 = iVar3;
    _strcmp();
    if (iVar4 == 0) {
      uVar6 = 4;
    }
    else {
      iVar4 = iVar3;
      _strcmp(iVar3,&a16);
      if (iVar4 != 0) {
        iVar4 = param_1;
        _objc_msgSend(param_1,paName);
        _IOLog(aSInvalidRingSp,iVar4);
      }
      uVar6 = 0x10;
    }
    *(undefined4 *)(param_1 + 300) = uVar6;
    pauVar2 = paFreestring;
    _objc_msgSend(param_3,paFreestring,iVar3);
    pauVar1 = paValueforstring;
    iVar3 = param_3;
    _objc_msgSend(param_3,paValueforstring,aNodeAddress);
    _objc_msgSend(param_3,pauVar2,iVar3);
    iVar3 = param_3;
    _objc_msgSend(param_3,pauVar1,a16mbEarlyToken);
    iVar4 = iVar3;
    _strcmp();
    if (iVar4 == 0) {
      uVar5 = *(uint *)(param_1 + 0x128) | 0x40000000;
    }
    else {
      uVar5 = *(uint *)(param_1 + 0x128) & 0xbfffffff;
    }
    *(uint *)(param_1 + 0x128) = uVar5;
    _objc_msgSend(param_3,paFreestring,iVar3);
    iVar3 = param_3;
    _objc_msgSend(param_3,paValueforstring,aAutoRecovery);
    iVar4 = iVar3;
    _strcmp();
    if (iVar4 == 0) {
      uVar5 = *(uint *)(param_1 + 0x128) | 0x20000000;
    }
    else {
      uVar5 = *(uint *)(param_1 + 0x128) & 0xdfffffff;
    }
    *(uint *)(param_1 + 0x128) = uVar5;
    _objc_msgSend(param_3,paFreestring,iVar3);
    *(undefined4 *)(param_1 + 0x134) = 0x1fa4;
    *(undefined4 *)(param_1 + 0x130) = 8;
    _ipforwarding = 0;
    uVar6 = 0;
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | 0x10000000;
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | 0x4000000;
  }
  return CONCAT44(param_2,uVar6);
}
