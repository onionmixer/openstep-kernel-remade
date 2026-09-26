
/* WARNING: Removing unreachable block (ram,0xf00d3e10) */
/* WARNING: Removing unreachable block (ram,0xf00d3df0) */
/* WARNING: Removing unreachable block (ram,0xf00d3d78) */
/* WARNING: Removing unreachable block (ram,0xf00d3e00) */
/* WARNING: Removing unreachable block (ram,0xf00d3e24) */
/* WARNING: Removing unreachable block (ram,0xf00d3d34) */

undefined8 -[EventDriver startCursor](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [14];
  undefined (*pauVar2) [26];
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
  if (*(int *)(param_1 + 0x188) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    if (*(char *)(param_1 + 0x1d2) == '\0') {
      iVar3 = *(int *)(param_1 + 0x110);
      pauVar2 = paUnlock;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x168);
      *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar3 + 0x18);
      *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar3 + 0x1a);
      iVar3 = param_1;
      _objc_msgSend(param_1,paPointtoscreen,(undefined *)((int)register0x00000038 + -0x18));
      *(int *)(param_1 + 0x18c) = iVar3;
      if (iVar3 < 0) {
        iVar3 = *(int *)(param_1 + 0x110);
        pauVar2 = paUnlock;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x180) + iVar3 * 0x14;
        *(undefined2 *)(param_1 + 400) = *(undefined2 *)(iVar3 + 0xc);
        pauVar1 = paSetbrightness_0;
        *(undefined2 *)(param_1 + 0x192) = *(undefined2 *)(iVar3 + 0xe);
        *(undefined2 *)(param_1 + 0x194) = *(undefined2 *)(iVar3 + 0x10);
        *(undefined2 *)(param_1 + 0x196) = *(undefined2 *)(iVar3 + 0x12);
        *(sword *)(param_1 + 0x192) = *(sword *)(param_1 + 0x192) + -1;
        *(sword *)(param_1 + 0x196) = *(sword *)(param_1 + 0x196) + -1;
        _objc_msgSend(param_1,pauVar1);
        _objc_msgSend(param_1,paShowcursor);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
        iVar3 = param_1;
        pauVar2 = paAttachdefaulte;
      }
    }
    _objc_msgSend(iVar3,pauVar2);
  }
  return CONCAT44(param_2,param_1);
}
