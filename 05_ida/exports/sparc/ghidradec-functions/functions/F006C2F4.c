
/* WARNING: Removing unreachable block (ram,0xf006c414) */
/* WARNING: Removing unreachable block (ram,0xf006c3c0) */
/* WARNING: Removing unreachable block (ram,0xf006c390) */
/* WARNING: Removing unreachable block (ram,0xf006c354) */
/* WARNING: Removing unreachable block (ram,0xf006c338) */
/* WARNING: Removing unreachable block (ram,0xf006c34c) */
/* WARNING: Removing unreachable block (ram,0xf006c384) */
/* WARNING: Removing unreachable block (ram,0xf006c3a4) */
/* WARNING: Removing unreachable block (ram,0xf006c3cc) */
/* WARNING: Removing unreachable block (ram,0xf006c41c) */
/* WARNING: Removing unreachable block (ram,0xf006c328) */

undefined8 _map_vnode(undefined4 *param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
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
  puVar5 = (undefined4 *)*param_1;
  wVar1 = *(word *)(puVar5 + 1);
  *(word *)(puVar5 + 1) = wVar1 + 1;
  if (((int)((uint)wVar1 * 0x10000) < 1) && ((puVar5[0xe] & 0x8000000) == 0)) {
    _vmp_get(puVar5);
    puVar2 = param_1;
    _vnode_pager_setup(param_1,0,1);
    *puVar5 = puVar2;
    _lock_write(_vm_alloc_lock);
    puVar3 = puVar2;
    _vm_object_lookup();
    puVar5[9] = puVar3;
    DAT_f013c26c._0_4_ = DAT_f013c26c._0_4_ + 1;
    if (puVar5[9] == 0) {
      uVar4 = 0;
      _vm_object_allocate();
      puVar5[9] = uVar4;
      _vm_object_enter();
      _vm_object_setpager(puVar5[9],puVar2,0,0);
    }
    else {
      DAT_f013c26c._4_4_ = DAT_f013c26c._4_4_ + 1;
    }
    _lock_done(_vm_alloc_lock);
    puVar5[0xd] = 0;
    puVar2 = param_1;
    _vnode_size();
    puVar5[5] = puVar2;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[0xe] = puVar5[0xe] | 0x8000000;
    if ((puVar5[5] != 0) && ((uint)puVar5[5] < _mfs_max_window)) {
      _remap_vnode(param_1,0);
    }
    _vmp_put(puVar5);
  }
  return CONCAT44(param_2,param_1);
}
