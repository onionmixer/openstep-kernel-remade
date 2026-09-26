
/* WARNING: Removing unreachable block (ram,0xf0022fa4) */
/* WARNING: Removing unreachable block (ram,0xf0022f60) */

undefined8 _unp_internalize(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar3 = 0;
  uVar4 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  piVar2 = (int *)(param_1 + *(int *)(param_1 + 4));
  if (uVar4 == 0) {
loc_F0022F8C:
    iVar3 = 0;
    piVar2 = (int *)(param_1 + *(int *)(param_1 + 4));
    if (uVar4 != 0) {
      do {
        iVar1 = *piVar2;
        iVar3 = iVar3 + 1;
        _getf();
        *piVar2 = iVar1;
        piVar2 = piVar2 + 1;
        *(sword *)(iVar1 + 0xe) = *(sword *)(iVar1 + 0xe) + 1;
        *(sword *)(iVar1 + 0x10) = *(sword *)(iVar1 + 0x10) + 1;
        _unp_rights = _unp_rights + 1;
      } while (iVar3 < (int)uVar4);
    }
    uVar5 = 0;
  }
  else {
    iVar1 = *piVar2;
    while( true ) {
      piVar2 = piVar2 + 1;
      _getf();
      iVar3 = iVar3 + 1;
      if (iVar1 == 0) break;
      if ((int)uVar4 <= iVar3) goto loc_F0022F8C;
      iVar1 = *piVar2;
    }
    uVar5 = 9;
  }
  return CONCAT44(param_2,uVar5);
}
