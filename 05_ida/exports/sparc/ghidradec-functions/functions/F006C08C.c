
/* WARNING: Removing unreachable block (ram,0xf006c124) */
/* WARNING: Removing unreachable block (ram,0xf006c0d8) */
/* WARNING: Removing unreachable block (ram,0xf006c164) */
/* WARNING: Removing unreachable block (ram,0xf006c0b0) */

undefined8 _mfs_init(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  dword_F013C21C = &_vm_info_queue;
  _vm_info_queue = &_vm_info_queue;
  _vm_info_lock_data = 0;
  _lock_init(_mfs_alloc_lock_data,1);
  _mfs_alloc_wanted = 0;
  uVar2 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),_mfs_map_size,1);
  _mfs_map_size = dword_F013C050;
  if (0x1000000 < dword_F013C050) {
    _mfs_map_size = 0x1000000;
  }
  _mfs_map = uVar2;
  if (_mfs_max_window == 0) {
    uVar1 = _mfs_map_size;
    .udiv(_mfs_map_size,0x14);
    _mfs_max_window = uVar1;
  }
  if (_mfs_max_window < 0x10000) {
    _mfs_max_window = 0x10000;
  }
  uVar2 = 0x3c;
  _zinit(0x3c,600000,0x2000,0,aVmInfoZone);
  _vm_info_zone = uVar2;
  return CONCAT44(param_2,param_1);
}
