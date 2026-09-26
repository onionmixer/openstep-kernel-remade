
/* WARNING: Removing unreachable block (ram,0xf00c1e40) */
/* WARNING: Removing unreachable block (ram,0xf00c1e74) */
/* WARNING: Removing unreachable block (ram,0xf00c1e20) */
/* WARNING: Removing unreachable block (ram,0xf00c1e64) */
/* WARNING: Removing unreachable block (ram,0xf00c1e84) */
/* WARNING: Removing unreachable block (ram,0xf00c1ebc) */
/* WARNING: Removing unreachable block (ram,0xf00c1df8) */

undefined8 -[TYPE5Keyboard becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined5 *puVar1;
  undefined (*pauVar2) [28];
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paLock);
  pauVar2 = paRelinquishowne;
  uVar3 = *(uint *)(param_1 + 0x140);
  if (uVar3 == 0) {
    *(undefined4 *)(param_1 + 0x140) = param_3;
    iVar6 = 0;
  }
  else {
    _objc_msgSend(uVar3,paRespondsto,paRelinquishowne);
    puVar1 = paName;
    if ((uVar3 & 0xff) == 0) {
      iVar6 = -0x2d5;
      iVar4 = param_1;
      _objc_msgSend(param_1,paName);
      uVar5 = *(undefined4 *)(param_1 + 0x140);
      _objc_msgSend(uVar5,puVar1);
      _IOLog(aSOwnerSDoesNot,iVar4,uVar5);
    }
    else {
      iVar6 = *(int *)(param_1 + 0x140);
      _objc_msgSend(iVar6,pauVar2,param_1);
    }
    if (iVar6 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x148);
      goto loc_F00C1EB8;
    }
    *(undefined4 *)(param_1 + 0x140) = param_3;
  }
  uVar5 = *(undefined4 *)(param_1 + 0x148);
  _type5kbd_owner = param_3;
loc_F00C1EB8:
  _objc_msgSend(uVar5,paUnlock);
  return CONCAT44(param_2,iVar6);
}
