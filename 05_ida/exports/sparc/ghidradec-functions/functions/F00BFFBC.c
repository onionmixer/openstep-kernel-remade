
/* WARNING: Removing unreachable block (ram,0xf00c0058) */
/* WARNING: Removing unreachable block (ram,0xf00c0020) */
/* WARNING: Removing unreachable block (ram,0xf00bfff4) */
/* WARNING: Removing unreachable block (ram,0xf00c0000) */
/* WARNING: Removing unreachable block (ram,0xf00c003c) */
/* WARNING: Removing unreachable block (ram,0xf00c0064) */
/* WARNING: Removing unreachable block (ram,0xf00bffe0) */

undefined8
-[EventSrcPCKeyboard relinquishOwnership:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
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
  
  uVar1 = paRelinquishowne_0;
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  _objc_msgSendSuper(puVar2,paRelinquishowne_0,param_3);
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  _wserver_on = 0;
  if ((puVar2 == (undefined *)0x0) &&
     (iVar3 = param_1, _objc_msgSend(param_1,paOwner_0), iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 300);
    _objc_msgSend(iVar3,uVar1,param_1);
    if (iVar3 == 0) {
      *(undefined *)(param_1 + 0x130) = 0;
    }
  }
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  return CONCAT44(param_2,puVar2);
}
