
/* WARNING: Removing unreachable block (ram,0xf00c0154) */
/* WARNING: Removing unreachable block (ram,0xf00c011c) */
/* WARNING: Removing unreachable block (ram,0xf00c00bc) */
/* WARNING: Removing unreachable block (ram,0xf00c00b0) */
/* WARNING: Removing unreachable block (ram,0xf00c00e8) */
/* WARNING: Removing unreachable block (ram,0xf00c0144) */
/* WARNING: Removing unreachable block (ram,0xf00c0160) */
/* WARNING: Removing unreachable block (ram,0xf00c009c) */

undefined8 -[EventSrcPCKeyboard becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [13];
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined *puVar5;
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
  
  uVar2 = uRamf0141d58;
  pauVar1 = paBecomeowner;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar5 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  puVar4 = puVar5;
  _objc_msgSendSuper(puVar5,paBecomeowner,param_3);
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  if ((puVar4 == (undefined *)0x0) && (*(char *)(param_1 + 0x130) == '\0')) {
    iVar3 = *(int *)(param_1 + 300);
    _objc_msgSend(iVar3,pauVar1,param_1);
    if (iVar3 == 0) {
      *(undefined *)(param_1 + 0x130) = 1;
      _wserver_on = 1;
    }
    else {
      iVar3 = *(int *)(param_1 + 300);
      _objc_msgSend(iVar3,paDesireownershi,param_1);
      if (iVar3 != 0) {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
        puVar4 = (undefined *)0xfffffd2b;
        _objc_msgSendSuper(puVar5,paRelinquishowne_0,param_3);
      }
    }
  }
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  return CONCAT44(param_2,puVar4);
}

