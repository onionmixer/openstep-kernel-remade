
/* WARNING: Removing unreachable block (ram,0xf00d4550) */
/* WARNING: Removing unreachable block (ram,0xf00d4530) */
/* WARNING: Removing unreachable block (ram,0xf00d453c) */
/* WARNING: Removing unreachable block (ram,0xf00d4588) */
/* WARNING: Removing unreachable block (ram,0xf00d4514) */

undefined8 -[EventDriver registerEventSource:](int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
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
  iVar2 = param_3;
  _objc_msgSend(param_3,paBecomeowner,param_1);
  if (iVar2 == 0) {
    piVar1 = (int *)0xc;
    _IOMalloc();
    _bzero();
    *piVar1 = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
    iVar2 = *(int *)(param_1 + 0x178);
    if (param_1 + 0x174 == iVar2) {
      *(int **)(param_1 + 0x174) = piVar1;
    }
    else {
      *(int **)(iVar2 + 4) = piVar1;
    }
    piVar1[2] = iVar2;
    piVar1[1] = param_1 + 0x174;
    *(int **)(param_1 + 0x178) = piVar1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paUnlock);
  }
  else {
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
