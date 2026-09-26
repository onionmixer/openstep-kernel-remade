
/* WARNING: Removing unreachable block (ram,0xf00d2698) */
/* WARNING: Removing unreachable block (ram,0xf00d2650) */
/* WARNING: Removing unreachable block (ram,0xf00d265c) */
/* WARNING: Removing unreachable block (ram,0xf00d26b4) */
/* WARNING: Removing unreachable block (ram,0xf00d25d8) */

undefined8 -[EventDriver _resetMouseParameters](int param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined7 *puVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
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
  
  puVar1 = paLock;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar3 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    *(undefined4 *)(param_1 + 0x1bc) = 0x1e;
    *(undefined2 *)(param_1 + 0x1b2) = 3;
    *(undefined2 *)(param_1 + 0x1b0) = 3;
    *(undefined4 *)(param_1 + 0x1b8) = 0xffffffe2;
    *(undefined2 *)(param_1 + 0x1ae) = 0xfffd;
    *(undefined2 *)(param_1 + 0x1ac) = 0xfffd;
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    puVar2 = paUnlock;
    *(int *)(param_1 + 0x1a4) = *(int *)(*(int *)(param_1 + 0x168) + 0x10) + 0x48a8;
    *(undefined4 *)(param_1 + 0x1a0) = 0x48a8;
    *(undefined4 *)(param_1 + 0x1c8) = 0x10;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar2);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),puVar1);
    puVar4 = *(undefined4 **)(param_1 + 0x174);
    if ((undefined4 *)(param_1 + 0x174) == puVar4) {
      uVar3 = *(undefined4 *)(param_1 + 0x170);
    }
    else {
      uVar3 = *puVar4;
      while( true ) {
        puVar4 = (undefined4 *)puVar4[1];
        _objc_msgSend(uVar3,paSetintvaluesFo_0,(undefined *)((int)register0x00000038 + -0x14),
                      aEvsResetmouse,1);
        if ((undefined4 *)(param_1 + 0x174) == puVar4) break;
        uVar3 = *puVar4;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x170);
    }
  }
  _objc_msgSend(uVar3,paUnlock);
  return CONCAT44(param_2,param_1);
}

