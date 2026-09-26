
/* WARNING: Removing unreachable block (ram,0xf0086778) */
/* WARNING: Removing unreachable block (ram,0xf0086648) */
/* WARNING: Removing unreachable block (ram,0xf0086790) */
/* WARNING: Removing unreachable block (ram,0xf0086624) */

undefined8 _vm_object_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
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
  uVar1 = 0x58;
  _zinit(0x58,_page_mask + 0x80000 & ~_page_mask,0,0,&aObjects);
  uVar2 = 0xc;
  _vm_object_zone = uVar1;
  _zinit(0xc,0x19000,0,0,aObjectHashZone);
  unk_F013D41C = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  dword_F013D834 = &_vm_object_list;
  _vm_object_list = &_vm_object_list;
  _vm_object_count = 0;
  _vm_cache_lock = 0;
  _vm_object_list_lock = 0;
  iVar4 = 0;
  puVar3 = _vm_object_hashtable;
  _object_hash_zone = uVar2;
  do {
    *(undefined **)(puVar3 + 4) = puVar3;
    *(undefined **)puVar3 = puVar3;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 8;
  } while (iVar4 < 0x80);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  DAT_f013d858._0_2_ = 1;
  DAT_f013d858._2_2_ = 0;
  DAT_f013d854._0_4_ = 0;
  DAT_f013d858._4_4_ = 0;
  DAT_f013d858._16_4_ = 0;
  DAT_f013d858._24_4_ = 0;
  DAT_f013d858._28_4_ = 0;
  DAT_f013d858._20_4_ = 0;
  DAT_f013d858._8_4_ = 0;
  DAT_f013d858._12_4_ = 0;
  DAT_f013d858._60_4_ = 0;
  _kernel_object = _kernel_object_store;
  DAT_f013d858._50_2_ = (word)DAT_f013d858._48_4_ & 0x7fff;
  DAT_f013d858._48_2_ = 2;
  DAT_f013d858._44_4_ = DAT_f013d858._44_4_ & 0xcfff | 0x800;
  __vm_object_allocate(0xf000000);
  _vm_submap_object = _vm_submap_object_store;
  __vm_object_allocate(0xf000000);
  return CONCAT44(param_2,param_1);
}
