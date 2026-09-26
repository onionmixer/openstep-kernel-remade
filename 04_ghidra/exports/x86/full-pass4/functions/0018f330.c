/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f330 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_init(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0xc);
  _kmem_alloc_wired(_kernel_map,&_pg_desc_tbl,iVar3 * 0x14);
  __pg_first_phys = uVar1;
  _pmap_zone = _zinit(0x1c,0x2bc0,0,0,&DAT_001e24cb);
  _pv_entry_zone = _zinit(0xc,120000,0,0,s_pv_entry_001e24d0);
  _pg_exten_zone = _zinit(0x20,iVar3 << 5,0,0,s_pg_exten_001e24d9);
  DAT_001f7acc = &_pt_active_queue;
  _pt_active_queue = &_pt_active_queue;
  DAT_001f7adc = &_pt_free_queue;
  _pt_free_queue = &_pt_free_queue;
  _DAT_001f7aac = &_pd_free_queue;
  _pd_free_queue = &_pd_free_queue;
  _vm_first_phys = uVar1;
  _vm_last_phys = uVar2;
  _pmap_initialized = 1;
  return;
}

