
/* WARNING: Removing unreachable block (ram,0xf0088e18) */
/* WARNING: Removing unreachable block (ram,0xf0088dfc) */
/* WARNING: Removing unreachable block (ram,0xf0088e3c) */
/* WARNING: Removing unreachable block (ram,0xf0088dc4) */

undefined8 _vm_page_insert(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
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
  int *piVar3;
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
  if ((*(uint *)(param_1 + 0x20) & 0x20000000) != 0) {
    _panic(aVmPageInsert);
  }
  *(int **)(param_1 + 0x14) = param_2;
  *(uint *)(param_1 + 0x18) = param_3;
  iVar1 = ((int)param_2 + (param_3 >> ((byte)_page_shift & 0x1f)) & _vm_page_hash_mask) * 8;
  piVar3 = (int *)(_vm_page_buckets + iVar1);
  _spltty();
  do {
    do {
    } while (*piVar3 != 0);
    piVar2 = piVar3;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(int *)(param_1 + 0x10) = piVar3[1];
  piVar3[1] = param_1;
  *piVar3 = 0;
  _splx(iVar1);
  piVar3 = (int *)param_2[1];
  if (param_2 == piVar3) {
    *param_2 = param_1;
  }
  else {
    piVar3[2] = param_1;
  }
  *(int **)(param_1 + 0xc) = piVar3;
  *(int **)(param_1 + 8) = param_2;
  param_2[1] = param_1;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20000000;
  *(sword *)((int)param_2 + 0x1a) = *(sword *)((int)param_2 + 0x1a) + 1;
  return CONCAT44(param_2,param_1);
}

