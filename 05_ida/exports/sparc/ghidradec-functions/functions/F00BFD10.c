
/* WARNING: Removing unreachable block (ram,0xf00bfe80) */
/* WARNING: Removing unreachable block (ram,0xf00bfddc) */
/* WARNING: Removing unreachable block (ram,0xf00bfdac) */
/* WARNING: Removing unreachable block (ram,0xf00bfd48) */
/* WARNING: Removing unreachable block (ram,0xf00bfd54) */
/* WARNING: Removing unreachable block (ram,0xf00bfdd0) */
/* WARNING: Removing unreachable block (ram,0xf00bfe34) */
/* WARNING: Removing unreachable block (ram,0xf00bfe54) */
/* WARNING: Removing unreachable block (ram,0xf00bfd24) */

undefined8
-[EventSrcPCKeyboard setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined (*pauVar2) [14];
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
  bool bVar4;
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
  _strcmp(param_4,aEvsSetkeyrepea);
  if (iVar1 == 0) {
    if (param_5 != 2) goto locret_F00BFE98;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    sub_F00BF1CC(param_3,param_1 + 0x168);
    bVar4 = *(int *)(param_1 + 0x168) != 0;
    pauVar2 = paUnlock;
    if (bVar4) {
      param_1 = *(int *)(param_1 + 0x124);
    }
    else if ((bVar4) || (*(uint *)(param_1 + 0x16c) < 16700000)) {
      *(undefined8 *)(param_1 + 0x168) = 16700000;
      param_1 = *(int *)(param_1 + 0x124);
      pauVar2 = paUnlock;
    }
    else {
      param_1 = *(int *)(param_1 + 0x124);
    }
  }
  else {
    iVar1 = param_4;
    _strcmp(param_4,aEvsSetinitialk);
    if (iVar1 == 0) {
      if (param_5 != 2) goto locret_F00BFE98;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
      sub_F00BF1CC(param_3,param_1 + 0x170);
      bVar4 = *(int *)(param_1 + 0x170) != 0;
      pauVar2 = paUnlock;
      if (bVar4) {
        param_1 = *(int *)(param_1 + 0x124);
      }
      else if ((bVar4) || (*(uint *)(param_1 + 0x174) < 16700000)) {
        *(undefined8 *)(param_1 + 0x170) = 16700000;
        param_1 = *(int *)(param_1 + 0x124);
        pauVar2 = paUnlock;
      }
      else {
        param_1 = *(int *)(param_1 + 0x124);
      }
    }
    else {
      iVar1 = param_4;
      _strcmp(param_4,aEvsResetkeyboa_0);
      pauVar2 = paResetkeyboard;
      if (iVar1 != 0) {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar3 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
        _objc_msgSendSuper(puVar3,paSetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar3 == (undefined *)0xfffffd39) {
          puVar3 = (undefined *)0xfffffd3e;
        }
        goto locret_F00BFE98;
      }
    }
  }
  puVar3 = (undefined *)0x0;
  _objc_msgSend(param_1,pauVar2);
locret_F00BFE98:
  return CONCAT44(param_2,puVar3);
}
