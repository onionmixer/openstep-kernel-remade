
/* WARNING: Removing unreachable block (ram,0xf005151c) */
/* WARNING: Removing unreachable block (ram,0xf00514ac) */
/* WARNING: Removing unreachable block (ram,0xf00514f8) */
/* WARNING: Removing unreachable block (ram,0xf00515b0) */
/* WARNING: Removing unreachable block (ram,0xf0051468) */

undefined8 sub_F0051444(undefined4 *param_1,undefined *param_2,int param_3,uint param_4)

{
  bool bVar1;
  word wVar3;
  int iVar2;
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
  if (param_3 == 1) {
    if (*(int *)*param_1 == 0) {
      iVar4 = param_1[0xc];
    }
    else {
      _vnode_uncache(param_1);
      iVar4 = param_1[0xc];
    }
  }
  else {
    iVar4 = param_1[0xc];
  }
  if ((*(word *)(iVar4 + 100) & 0xf000) == 0x8000) {
    wVar3 = *(word *)(iVar4 + 0x44);
    bVar1 = true;
    if ((wVar3 & 1) != 0) {
      do {
        *(word *)(iVar4 + 0x44) = wVar3 | 0x10;
        _sleep(iVar4,10);
        wVar3 = *(word *)(iVar4 + 0x44);
      } while ((wVar3 & 1) != 0);
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    *(word *)(iVar4 + 0x44) = wVar3 | 1;
    if (((param_4 & 2) != 0) && (param_3 == 1)) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar4 + 0x70);
    }
  }
  else {
    bVar1 = false;
  }
  iVar2 = iVar4;
  sub_F00515C0(iVar4,param_2,param_3,param_4);
  if ((*(word *)(iVar4 + 0x44) & 0x46) != 0) {
    *(word *)(iVar4 + 0x44) = *(word *)(iVar4 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar4 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar4 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar4 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar4 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar4 + 0x44) & 0x40) == 0) {
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    else {
      *(undefined4 *)(iVar4 + 0x4c) = 0;
      *(undefined4 *)(iVar4 + 0x84) = _iuniqtime;
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    *(word *)(iVar4 + 0x44) = wVar3 & 0xffb9;
  }
  if (bVar1) {
    wVar3 = *(word *)(iVar4 + 0x44);
    *(word *)(iVar4 + 0x44) = wVar3 & 0xfffe;
    if ((wVar3 & 0x10) != 0) {
      *(word *)(iVar4 + 0x44) = wVar3 & 0xffee;
      _wakeup(iVar4);
    }
  }
  return CONCAT44(param_2,iVar2);
}
