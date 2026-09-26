/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ipc_bootstrap(void)

{
  _ipc_port_multiple_lock_data = 0;
  _ipc_port_timestamp_lock_data = 0;
  _ipc_port_timestamp_data = 0;
  _ipc_space_zone = _zinit(0x48,_ipc_space_max * 0x48,0x48,0,s_ipc_spaces_001de6d0);
  _zchange(_ipc_space_zone,0,0,1,0);
  _ipc_tree_entry_zone = _zinit(0x20,_ipc_tree_entry_max << 5,0x20,0,s_ipc_tree_entries_001de6db);
  _zchange(_ipc_tree_entry_zone,0,0,1,0);
  _ipc_object_zones = _zinit(0x50,_ipc_port_max * 0x50,0x50,0,s_ipc_ports_001de6ec);
  _zchange(_ipc_object_zones,0,0,1,0);
  _DAT_001f6234 = _zinit(0x1c,_ipc_pset_max * 0x1c,0x1c,0,s_ipc_port_sets_001de6f6);
  _zchange(_DAT_001f6234,0,0,1,0);
  _ipc_space_create_special(&_ipc_space_kernel);
  _ipc_space_create_special(&_ipc_space_reply);
  _ipc_table_init();
  _ipc_notify_init();
  _ipc_hash_init();
  _ipc_marequest_init();
  return;
}

