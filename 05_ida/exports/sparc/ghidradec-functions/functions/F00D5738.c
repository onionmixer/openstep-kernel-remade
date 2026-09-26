
/* WARNING: Removing unreachable block (ram,0xf00d5788) */
/* WARNING: Removing unreachable block (ram,0xf00d57ac) */
/* WARNING: Removing unreachable block (ram,0xf00d576c) */
/* WARNING: Removing unreachable block (ram,0xf00d57b8) */
/* WARNING: Removing unreachable block (ram,0xf00d57e0) */
/* WARNING: Removing unreachable block (ram,0xf00d5744) */

undefined8 -[IOEventSource becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [21];
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  pauVar1 = paRelinquishowne_0;
  uVar2 = *(uint *)(param_1 + 0x108);
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x108) = param_3;
    iVar5 = 0;
  }
  else {
    _objc_msgSend(uVar2,paRespondsto,paRelinquishowne_0);
    if ((uVar2 & 0xff) == 0) {
      iVar5 = -0x2d5;
      iVar3 = param_1;
      _objc_msgSend(param_1,paName);
      _IOLog(aSOwnerDoesNotR,iVar3);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x108);
      _objc_msgSend(iVar5,pauVar1,param_1);
    }
    if (iVar5 != 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D57DC;
    }
    *(undefined4 *)(param_1 + 0x108) = param_3;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x110);
loc_F00D57DC:
  _objc_msgSend(uVar4,paUnlock);
  return CONCAT44(param_2,iVar5);
}
