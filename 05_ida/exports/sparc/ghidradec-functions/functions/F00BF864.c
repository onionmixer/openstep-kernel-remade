
/* WARNING: Removing unreachable block (ram,0xf00bf904) */
/* WARNING: Removing unreachable block (ram,0xf00bf8e0) */
/* WARNING: Removing unreachable block (ram,0xf00bf8b0) */
/* WARNING: Removing unreachable block (ram,0xf00bf890) */
/* WARNING: Removing unreachable block (ram,0xf00bf8c4) */
/* WARNING: Removing unreachable block (ram,0xf00bf8f4) */
/* WARNING: Removing unreachable block (ram,0xf00bf934) */
/* WARNING: Removing unreachable block (ram,0xf00bf870) */

undefined8 -[EventSrcPCKeyboard init](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paFree);
  }
  uVar1 = paKeymap;
  _objc_msgSend(paKeymap,paAlloc);
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  _objc_msgSend();
  _objc_msgSend(param_1,paInitkeyboard);
  *(undefined8 *)(param_1 + 0x168) = 125000000;
  uVar1 = paUnlock;
  *(undefined8 *)(param_1 + 0x170) = 500000000;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),uVar1);
  return CONCAT44(param_2,param_1);
}
