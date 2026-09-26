
/* WARNING: Removing unreachable block (ram,0xf0088ee8) */
/* WARNING: Removing unreachable block (ram,0xf0088f34) */
/* WARNING: Removing unreachable block (ram,0xf0088ecc) */

undefined8 _vm_page_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
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
  if ((*(uint *)(param_1 + 0x20) & 0x20000000) != 0) {
    iVar1 = (*(int *)(param_1 + 0x14) + (*(uint *)(param_1 + 0x18) >> ((byte)_page_shift & 0x1f)) &
            _vm_page_hash_mask) * 8;
    piVar5 = (int *)(_vm_page_buckets + iVar1);
    _spltty();
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = piVar5[1];
    if (iVar3 == param_1) {
      piVar5[1] = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        puVar4 = (undefined4 *)(iVar3 + 0x10);
        iVar3 = *(int *)(iVar3 + 0x10);
      } while (iVar3 != param_1);
      *puVar4 = *(undefined4 *)(iVar3 + 0x10);
    }
    *piVar5 = 0;
    _splx(iVar1);
    iVar1 = *(int *)(param_1 + 8);
    piVar5 = *(int **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x14) == iVar1) {
      *(int **)(iVar1 + 4) = piVar5;
    }
    else {
      *(int **)(iVar1 + 0xc) = piVar5;
    }
    if (*(int **)(param_1 + 0x14) == piVar5) {
      *piVar5 = iVar1;
    }
    else {
      piVar5[2] = iVar1;
    }
    *(sword *)(*(int *)(param_1 + 0x14) + 0x1a) = *(sword *)(*(int *)(param_1 + 0x14) + 0x1a) + -1;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xdfffffff;
  }
  return CONCAT44(param_2,param_1);
}

