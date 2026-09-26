
/* WARNING: Removing unreachable block (ram,0xf00d44d4) */
/* WARNING: Removing unreachable block (ram,0xf00d44bc) */
/* WARNING: Removing unreachable block (ram,0xf00d44a4) */
/* WARNING: Removing unreachable block (ram,0xf00d44c8) */
/* WARNING: Removing unreachable block (ram,0xf00d44f4) */
/* WARNING: Removing unreachable block (ram,0xf00d4444) */

undefined8 -[EventDriver detachEventSources](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
  iVar3 = param_1 + 0x174;
  if (iVar3 == *(int *)(param_1 + 0x174)) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  else {
    piVar5 = *(int **)(param_1 + 0x174);
    while( true ) {
      iVar4 = piVar5[1];
      iVar2 = piVar5[2];
      if (iVar3 == iVar4) {
        *(int *)(param_1 + 0x178) = iVar2;
      }
      else {
        *(int *)(iVar4 + 8) = iVar2;
      }
      if (iVar3 == iVar2) {
        *(int *)(param_1 + 0x174) = iVar4;
      }
      else {
        *(int *)(iVar2 + 4) = iVar4;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paUnlock);
      if (*piVar5 != 0) {
        _objc_msgSend(*piVar5,paRelinquishowne_0,param_1);
      }
      _IOFree(piVar5,0xc);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
      if (iVar3 == *(int *)(param_1 + 0x174)) break;
      piVar5 = *(int **)(param_1 + 0x174);
    }
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}

