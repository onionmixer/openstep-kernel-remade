
/* WARNING: Removing unreachable block (ram,0xf009f704) */
/* WARNING: Removing unreachable block (ram,0xf009f6bc) */
/* WARNING: Removing unreachable block (ram,0xf009f6fc) */
/* WARNING: Removing unreachable block (ram,0xf009f70c) */
/* WARNING: Removing unreachable block (ram,0xf009f670) */

undefined8 _pmap_activate(int *param_1,int param_2)

{
  undefined4 unaff_l0;
  int *piVar1;
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
  dword_F013DF04 = dword_F013DF04 + 1;
  if (((_active_pmap != param_1) || (param_1[5] == 0)) || (*(int **)(param_1[5] + 8) != param_1)) {
    DAT_f013df08 = DAT_f013df08 + 1;
    do {
      do {
      } while (param_1[6] != 0);
      piVar1 = param_1 + 6;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1 == _kernel_pmap) || (*(int *)(*(int *)(param_2 + 0xc) + 0x4c) != 0)) {
      piVar1 = (int *)0x0;
      param_1[5] = _context_table;
    }
    else {
      piVar1 = param_1;
      _pmap_alloc_context();
      *(uint *)(_contexts + (int)piVar1 * 4) =
           (*(int *)(*(int *)(*param_1 + 4) + 4) + (uint)*(byte *)(*param_1 + 0xe) * 0x400 >> 6) <<
           2 | 1;
    }
    _mmu_flushctx(piVar1);
    _vac_ctxflush(piVar1);
    _mmu_setctx(piVar1);
    _active_pmap = param_1;
    param_1[6] = 0;
  }
  return CONCAT44(param_2,param_1);
}

