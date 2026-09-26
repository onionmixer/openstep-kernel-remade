
/* WARNING: Removing unreachable block (ram,0xf00ccf94) */
/* WARNING: Removing unreachable block (ram,0xf00ccf5c) */
/* WARNING: Removing unreachable block (ram,0xf00ccfcc) */
/* WARNING: Removing unreachable block (ram,0xf00ccfd4) */
/* WARNING: Removing unreachable block (ram,0xf00ccf80) */
/* WARNING: Removing unreachable block (ram,0xf00ccfb8) */
/* WARNING: Removing unreachable block (ram,0xf00ccf10) */

undefined8 -[IOTokenRing commandRequestOccurred](uint param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 uVar4;
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
  iVar2 = *(int *)(param_1 + 0x154);
  uVar4 = 0;
  _objc_msgSend(iVar2,paOper_0);
  if (iVar2 == 2) {
    _objc_msgSend(param_1,paResetandenable,0);
    puVar1 = paDone;
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & 0x7fffffff;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x154),puVar1,0);
  }
  else if (iVar2 < 3) {
    if (iVar2 == 1) {
      if ((-1 < *(int *)(param_1 + 0x128)) &&
         (uVar3 = param_1, _objc_msgSend(param_1,paResetandenable,1), (uVar3 & 0xff) == 0)) {
        uVar4 = 5;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x154),paDone,uVar4);
    }
  }
  else if (iVar2 == 4) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x154),paDone,0);
    _IOExitThread();
  }
  return CONCAT44(param_2,param_1);
}
