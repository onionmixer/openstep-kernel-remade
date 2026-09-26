
/* WARNING: Removing unreachable block (ram,0xf00c1f84) */
/* WARNING: Removing unreachable block (ram,0xf00c1f40) */
/* WARNING: Removing unreachable block (ram,0xf00c1f08) */
/* WARNING: Removing unreachable block (ram,0xf00c1f78) */
/* WARNING: Removing unreachable block (ram,0xf00c1f5c) */
/* WARNING: Removing unreachable block (ram,0xf00c1ed8) */

undefined8 -[TYPE5Keyboard relinquishOwnership:](int param_1,undefined4 param_2,uint param_3)

{
  undefined (*pauVar1) [16];
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paLock);
  iVar3 = -0x2d5;
  if (*(uint *)(param_1 + 0x140) == param_3) {
    iVar3 = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    _type5kbd_owner = 0;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x148),paUnlock);
  pauVar1 = paCanbecomeowner;
  if (iVar3 == 0) {
    uVar2 = *(uint *)(param_1 + 0x144);
    if ((uVar2 != 0) && (uVar2 != param_3)) {
      _objc_msgSend(uVar2,paRespondsto,paCanbecomeowner);
      if ((uVar2 & 0xff) == 0) {
        _objc_msgSend(param_1,paName);
        _IOLog(aSDesiredownerD_0,param_1);
      }
      else {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x144),pauVar1,param_1);
      }
    }
  }
  return CONCAT44(param_2,iVar3);
}

