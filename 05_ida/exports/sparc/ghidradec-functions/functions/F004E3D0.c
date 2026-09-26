
/* WARNING: Removing unreachable block (ram,0xf004e4bc) */
/* WARNING: Removing unreachable block (ram,0xf004e480) */
/* WARNING: Removing unreachable block (ram,0xf004e434) */
/* WARNING: Removing unreachable block (ram,0xf004e4a4) */
/* WARNING: Removing unreachable block (ram,0xf004e4f0) */
/* WARNING: Removing unreachable block (ram,0xf004e408) */

undefined8 _iinactive(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
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
  if ((((*(word *)(param_1 + 0x44) & 0x101) != 0x100) || (*(int *)(param_1 + 0x60) != 0)) ||
     (*(int *)(param_1 + 0x5c) != 0)) {
    _panic(aIinactive);
  }
  if (*(char *)(*(int *)(param_1 + 0x50) + 0xd2) == '\0') {
    wVar1 = *(word *)(param_1 + 0x44);
    while ((wVar1 & 1) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 | 0x10;
      _sleep(param_1,10);
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
    if (*(sword *)(param_1 + 0x66) < 1) {
      *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x200;
      _itrunc(param_1,0);
      *(undefined4 *)(param_1 + 0x8c) = 0;
      uVar2 = *(undefined2 *)(param_1 + 100);
      *(undefined2 *)(param_1 + 100) = 0;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      _ifree(param_1,*(undefined4 *)(param_1 + 0x48),uVar2);
    }
    if ((*(word *)(param_1 + 0x44) & 0x4e) != 0) {
      _iupdat(param_1,0);
    }
    wVar1 = *(word *)(param_1 + 0x44);
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
  iVar3 = _ifreeh;
  *(undefined2 *)(param_1 + 0x44) = 0;
  piVar5 = &_ifreeh;
  iVar4 = param_1;
  if (iVar3 != 0) {
    *_ifreet = param_1;
    piVar5 = _ifreet;
    iVar4 = _ifreeh;
  }
  _ifreeh = iVar4;
  *(int **)(param_1 + 0x60) = piVar5;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  _ifreet = (int *)(param_1 + 0x5c);
  return CONCAT44(param_2,param_1);
}
