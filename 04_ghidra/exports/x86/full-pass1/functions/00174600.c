/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174600 */

void _vm_map_init(void)

{
  _vm_map_zone = _zinit(0x50,0x19000,0,0,&DAT_001e0a73);
  _vm_map_entry_zone = _zinit(0x2c,0x100000,0,0,s_non_kernel_map_entries_001e0a78);
  _vm_map_kentry_zone = _zinit(0x2c,_kentry_data_size,0,0,s_kernel_map_entries_001e0a8f);
  _zchange(_vm_map_kentry_zone,0,0,0,0);
  _zcram(_vm_map_zone,_map_data,_map_data_size);
  _zcram(_vm_map_kentry_zone,_kentry_data,_kentry_data_size);
  return;
}

