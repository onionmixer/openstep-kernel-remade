
void _ipc_bootstrap(void)

{
  _ipc_port_timestamp_data = 0;
  _ipc_space_zone = _zinit(0x40,_ipc_space_max << 6,0x40,0,aIpcSpaces);
  _zchange(_ipc_space_zone,0,0,1,0);
  _ipc_tree_entry_zone = _zinit(0x20,_ipc_tree_entry_max << 5,0x20,0,aIpcTreeEntries);
  _zchange(_ipc_tree_entry_zone,0,0,1,0);
  _ipc_object_zones = _zinit(0x48,_ipc_port_max * 0x48,0x48,0,aIpcPorts);
  _zchange(_ipc_object_zones,0,0,1,0);
  dword_40C21D4 = _zinit(0x14,_ipc_pset_max * 0x14,0x14,0,aIpcPortSets);
  _zchange(dword_40C21D4,0,0,1,0);
  _ipc_space_create_special(&_ipc_space_kernel);
  _ipc_space_create_special(&_ipc_space_reply);
  _ipc_table_init();
  _ipc_notify_init();
  _ipc_hash_init();
  _ipc_marequest_init();
  return;
}
