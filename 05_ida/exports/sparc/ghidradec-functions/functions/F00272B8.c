
/* WARNING: Removing unreachable block (ram,0xf00272d8) */
/* WARNING: Removing unreachable block (ram,0xf00272f0) */
/* WARNING: Removing unreachable block (ram,0xf002733c) */
/* WARNING: Removing unreachable block (ram,0xf00272bc) */

undefined8 _pn_get(int param_1,int param_2,int param_3)

{
  int iVar1;
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
  bool bVar2;
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
  _pn_alloc(param_3);
  if (param_2 == 0) {
    _copyinstr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  else {
    _copystr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  iVar1 = *(int *)(param_3 + 8);
  bVar2 = false;
  if ((param_1 == 0) && (bVar2 = true, iVar1 == 0x400)) {
    if (*(char *)(*(int *)(param_3 + 4) + 0x3ff) != '\0') {
      param_1 = 0x3f;
    }
    iVar1 = *(int *)(param_3 + 8);
    bVar2 = param_1 == 0;
  }
  *(int *)(param_3 + 8) = iVar1 + -1;
  if (!bVar2) {
    _pn_free(param_3);
  }
  return CONCAT44(param_2,param_1);
}
