
/* WARNING: Removing unreachable block (ram,0xf00107fc) */
/* WARNING: Removing unreachable block (ram,0xf00107bc) */
/* WARNING: Removing unreachable block (ram,0xf0010748) */
/* WARNING: Removing unreachable block (ram,0xf00106dc) */
/* WARNING: Removing unreachable block (ram,0xf00106b8) */
/* WARNING: Removing unreachable block (ram,0xf001072c) */
/* WARNING: Removing unreachable block (ram,0xf0010790) */
/* WARNING: Removing unreachable block (ram,0xf00107e4) */
/* WARNING: Removing unreachable block (ram,0xf0010814) */
/* WARNING: Removing unreachable block (ram,0xf00106a8) */

undefined8 _kill_tasks(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  iVar2 = 0;
  _pmap_create();
  _vm_map_create();
  do {
    do {
    } while (_all_psets_lock != 0);
    puVar3 = &_all_psets_lock;
    _simple_lock_try();
  } while (puVar3 == (undefined4 *)0x0);
  puVar3 = _all_psets;
  if ((undefined4 **)_all_psets != &_all_psets) {
    do {
      puVar6 = (undefined4 *)DAT_f013510c._0_4_;
      if (puVar3 != (undefined4 *)_default_pset) {
        _all_psets_lock = 0;
        _processor_set_destroy(puVar3);
        do {
          do {
          } while (_all_psets_lock != 0);
          puVar3 = &_all_psets_lock;
          _simple_lock_try();
          puVar6 = _all_psets;
        } while (puVar3 == (undefined4 *)0x0);
      }
      puVar3 = puVar6;
    } while ((undefined4 **)puVar6 != &_all_psets);
  }
  _all_psets_lock = 0;
  do {
    do {
    } while (unk_F0135118._0_4_ != 0);
    puVar4 = unk_F0135118;
    _simple_lock_try();
  } while (puVar4 == (undefined *)0x0);
  while (iVar1 = DAT_f01350ec._0_4_, DAT_f01350f4 != 0) {
    DAT_f01350ec._0_4_ = iVar1;
    _pset_remove_task(_default_pset,iVar1);
    iVar5 = *(int *)(iVar1 + 0xc);
    if ((iVar5 != _kernel_map) && (iVar5 != iVar2)) {
      *(int *)(iVar1 + 0xc) = iVar2;
      _vm_map_reference(iVar2);
      unk_F0135118._0_4_ = 0;
      _vm_map_remove(iVar5,*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18));
      do {
        do {
        } while (unk_F0135118._0_4_ != 0);
        puVar4 = unk_F0135118;
        _simple_lock_try();
      } while (puVar4 == (undefined *)0x0);
    }
  }
  DAT_f01350ec._0_4_ = iVar1;
  unk_F0135118._0_4_ = 0;
  return CONCAT44(param_2,param_1);
}
