
/* WARNING: Removing unreachable block (ram,0xf00bff70) */
/* WARNING: Removing unreachable block (ram,0xf00bff3c) */
/* WARNING: Removing unreachable block (ram,0xf00bff00) */
/* WARNING: Removing unreachable block (ram,0xf00bfed8) */
/* WARNING: Removing unreachable block (ram,0xf00bfec4) */
/* WARNING: Removing unreachable block (ram,0xf00bfee8) */
/* WARNING: Removing unreachable block (ram,0xf00bff18) */
/* WARNING: Removing unreachable block (ram,0xf00bff54) */
/* WARNING: Removing unreachable block (ram,0xf00bff9c) */
/* WARNING: Removing unreachable block (ram,0xf00bfeb0) */

undefined8
-[EventSrcPCKeyboard setCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
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
  puVar3 = (undefined *)0xfffffd3e;
  iVar1 = param_4;
  _strcmp(param_4,aEvsSetkeymappi);
  if (iVar1 == 0) {
    uVar2 = param_5;
    _IOMalloc(param_5);
    _bcopy(param_3,uVar2,param_5);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    iVar4 = *(int *)(param_1 + 0x128);
    iVar1 = paKeymap;
    _objc_msgSend(paKeymap,paAlloc);
    _objc_msgSend();
    *(int *)(param_1 + 0x128) = iVar1;
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x128) = iVar4;
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
      if (iVar4 != 0) {
        _objc_msgSend(iVar4,paFree);
      }
      puVar3 = (undefined *)0x0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paSetdelegate,param_1);
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    _objc_msgSend(uVar2,paUnlock);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
    _objc_msgSendSuper(puVar3,paSetcharvaluesF_0,param_3,param_4,param_5);
    if (puVar3 == (undefined *)0xfffffd39) {
      puVar3 = (undefined *)0xfffffd3e;
    }
  }
  return CONCAT44(param_2,puVar3);
}
