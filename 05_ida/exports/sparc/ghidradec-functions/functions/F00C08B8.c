
/* WARNING: Removing unreachable block (ram,0xf00c096c) */
/* WARNING: Removing unreachable block (ram,0xf00c0940) */
/* WARNING: Removing unreachable block (ram,0xf00c090c) */
/* WARNING: Removing unreachable block (ram,0xf00c091c) */
/* WARNING: Removing unreachable block (ram,0xf00c095c) */
/* WARNING: Removing unreachable block (ram,0xf00c09a8) */
/* WARNING: Removing unreachable block (ram,0xf00c08cc) */

undefined8
-[EventSrcPCPointer setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int *param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar3;
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
  puVar3 = (undefined *)0xfffffd3e;
  iVar2 = param_4;
  _strcmp(param_4,aEvsSetmousesca);
  if (iVar2 == 0) {
    if ((param_5 < 0x2a) && (*param_3 * 2 + 1U <= param_5)) {
      puVar3 = (undefined *)0x0;
      _objc_msgSend(param_1,paSetpointerscal,*param_3,param_3 + 1);
    }
  }
  else {
    iVar2 = param_4;
    _strcmp(param_4,aEvsSetmousehan);
    if (iVar2 == 0) {
      if (param_5 == 1) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
        uVar1 = paUnlock;
        puVar3 = (undefined *)0x0;
        *(int *)(param_1 + 0x134) = *param_3;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),uVar1);
      }
    }
    else {
      iVar2 = param_4;
      _strcmp(param_4,aEvsResetmouse_0);
      if (iVar2 == 0) {
        puVar3 = (undefined *)0x0;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar3 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
        _objc_msgSendSuper(puVar3,paSetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar3 == (undefined *)0xfffffd39) {
          puVar3 = (undefined *)0xfffffd3e;
        }
      }
    }
  }
  return CONCAT44(param_2,puVar3);
}
