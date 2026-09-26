
/* WARNING: Removing unreachable block (ram,0xf00c0628) */
/* WARNING: Removing unreachable block (ram,0xf00c0600) */
/* WARNING: Removing unreachable block (ram,0xf00c05c8) */
/* WARNING: Removing unreachable block (ram,0xf00c05e8) */
/* WARNING: Removing unreachable block (ram,0xf00c0614) */
/* WARNING: Removing unreachable block (ram,0xf00c0644) */
/* WARNING: Removing unreachable block (ram,0xf00c05b4) */

undefined8 -[EventSrcPCPointer init](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [12];
  int iVar2;
  undefined4 uVar3;
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
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 == 0) {
    uVar3 = paNxlock;
    _objc_msgSend(paNxlock,paNew);
    *(undefined4 *)(param_1 + 0x124) = uVar3;
    iVar2 = *(int *)(param_1 + 0x124);
  }
  _objc_msgSend(iVar2,paLock);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  *(undefined4 *)(param_1 + 0x128) = 0;
  pauVar1 = paInitpointer;
  *(undefined4 *)(param_1 + 0x134) = 0;
  iVar2 = param_1;
  _objc_msgSend(param_1,pauVar1);
  uVar3 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar3,paGetresolution);
  *(undefined4 *)(param_1 + 0x130) = uVar3;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paUnlock);
  _objc_msgSend(param_1,paSetpointerscal,5,unk_F00F91EC);
  return CONCAT44(param_2,iVar2);
}
