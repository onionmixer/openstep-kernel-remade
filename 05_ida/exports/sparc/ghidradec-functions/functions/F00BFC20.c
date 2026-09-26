
/* WARNING: Removing unreachable block (ram,0xf00bfcc4) */
/* WARNING: Removing unreachable block (ram,0xf00bfc9c) */
/* WARNING: Removing unreachable block (ram,0xf00bfc50) */
/* WARNING: Removing unreachable block (ram,0xf00bfc6c) */
/* WARNING: Removing unreachable block (ram,0xf00bfca8) */
/* WARNING: Removing unreachable block (ram,0xf00bfcf0) */
/* WARNING: Removing unreachable block (ram,0xf00bfc34) */

undefined8
-[EventSrcPCKeyboard getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar5 = *param_5;
  iVar1 = param_4;
  _strcmp(param_4,aEvsCurrentkeym_0);
  if (iVar1 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    uVar4 = *(uint *)(param_1 + 0x128);
    if (uVar4 == 0) {
      puVar3 = (undefined *)0xfffffd27;
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
      _objc_msgSend(uVar4,paKeymappingleng);
      if (uVar5 <= uVar4) {
        uVar4 = uVar5;
      }
      *param_5 = uVar4;
      puVar3 = (undefined *)0x0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paKeymapping,0);
      _bcopy();
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    _objc_msgSend(uVar2,paUnlock);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
    _objc_msgSendSuper(puVar3,paGetcharvaluesF_0,param_3,param_4,param_5);
    if (puVar3 == (undefined *)0xfffffd39) {
      puVar3 = (undefined *)0xfffffd3e;
    }
  }
  return CONCAT44(param_2,puVar3);
}
