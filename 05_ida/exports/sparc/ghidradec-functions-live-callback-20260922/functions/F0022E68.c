
/* WARNING: Removing unreachable block (ram,0xf0022ee8) */
/* WARNING: Removing unreachable block (ram,0xf0022ed4) */
/* WARNING: Removing unreachable block (ram,0xf0022e9c) */
/* WARNING: Removing unreachable block (ram,0xf0022e78) */

undefined8 _unp_externalize(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
  undefined4 uVar6;
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
  iVar1 = *(int *)(param_1 + 4);
  piVar5 = (int *)(param_1 + iVar1);
  uVar4 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  _ufavail();
  iVar3 = 0;
  if (iVar1 < (int)uVar4) {
    if (uVar4 == 0) {
      uVar6 = 0x28;
    }
    else {
      do {
        iVar3 = iVar3 + 1;
        _unp_discard(*piVar5);
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
      } while (iVar3 < (int)uVar4);
      uVar6 = 0x28;
    }
  }
  else if (uVar4 == 0) {
    uVar6 = 0;
  }
  else {
    do {
      iVar1 = 0;
      _ufalloc();
      if (iVar1 < 0) {
        _panic(aUnpExternalize);
        iVar2 = *piVar5;
      }
      else {
        iVar2 = *piVar5;
      }
      iVar3 = iVar3 + 1;
      _unp_rights = _unp_rights + -1;
      *(int *)(*(int *)(_active_u + 0x14c) + iVar1 * 4) = iVar2;
      *(sword *)(iVar2 + 0x10) = *(sword *)(iVar2 + 0x10) + -1;
      *piVar5 = iVar1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < (int)uVar4);
    uVar6 = 0;
  }
  return CONCAT44(param_2,uVar6);
}

