
/* WARNING: Removing unreachable block (ram,0xf0014358) */
/* WARNING: Removing unreachable block (ram,0xf0014320) */
/* WARNING: Removing unreachable block (ram,0xf0014338) */
/* WARNING: Removing unreachable block (ram,0xf00143c4) */
/* WARNING: Removing unreachable block (ram,0xf00142e4) */

undefined8 _logread(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = 0;
  _splusclock();
  if (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4)) {
    do {
      if ((_logsoftc & 2) != 0) {
        _splx(param_1);
        iVar4 = 0x23;
        goto locret_F001440C;
      }
      _logsoftc = _logsoftc | 8;
      _sleep(_pmsgbuf,0x1a);
    } while (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4));
  }
  _splx(param_1);
  _logsoftc = _logsoftc & 0xfffffff7;
  iVar1 = *(int *)(param_2 + 0x14);
  while (0 < iVar1) {
    iVar3 = *(int *)(_pmsgbuf + 8);
    iVar1 = *(int *)(_pmsgbuf + 4) - iVar3;
    if (iVar1 < 0) {
      iVar1 = 0xff4 - iVar3;
    }
    if (*(int *)(param_2 + 0x14) < iVar1) {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    if (iVar1 == 0) break;
    iVar4 = _pmsgbuf + iVar3 + 0xc;
    _uiomove(iVar4,iVar1,0,param_2);
    iVar3 = _pmsgbuf;
    if (iVar4 != 0) break;
    uVar2 = *(int *)(_pmsgbuf + 8) + iVar1;
    *(uint *)(_pmsgbuf + 8) = uVar2;
    if (((int)uVar2 < 0) || (0xff3 < uVar2)) {
      *(undefined4 *)(iVar3 + 8) = 0;
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x14);
    }
  }
locret_F001440C:
  return CONCAT44(param_2,iVar4);
}

