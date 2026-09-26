
/* WARNING: Removing unreachable block (ram,0xf00521e8) */
/* WARNING: Removing unreachable block (ram,0xf0052228) */
/* WARNING: Removing unreachable block (ram,0xf0052204) */

undefined8 sub_F00521B4(int param_1,undefined *param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  int iVar3;
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
  if (*(int *)(param_1 + 0x28) == 5) {
    iVar3 = *(int *)(param_1 + 0x30);
    iVar2 = iVar3 + 0x8c;
    if ((*(uint *)(iVar3 + 200) & 1) == 0) {
      iVar2 = iVar3;
      sub_F00515C0(iVar3,param_2,0,0);
    }
    else {
      _uiomove(iVar2,*(undefined4 *)(iVar3 + 0x70),0);
    }
    if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
      *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
      param_2 = DAT_f0135000;
      _microtime(&_iuniqtime);
      if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      else {
        *(undefined4 *)(iVar3 + 0x4c) = 0;
        *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
    }
  }
  else {
    iVar2 = 0x16;
  }
  return CONCAT44(param_2,iVar2);
}

