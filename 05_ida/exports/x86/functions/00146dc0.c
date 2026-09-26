/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146dc0. */
int ipc_bootstrap()
{
  ipc_port_multiple_lock_data = 0; /*0x146dc3*/
  ipc_port_timestamp_lock_data = 0; /*0x146dcd*/
  ipc_port_timestamp_data = 0; /*0x146dd7*/
  ipc_space_zone = zinit(72, 72 * ipc_space_max, 72, 0, aIpcSpaces); /*0x146dfd*/
  zchange(ipc_space_zone, 0, 0, 1, 0); /*0x146e0b*/
  ipc_tree_entry_zone = zinit(32, 32 * ipc_tree_entry_max, 32, 0, aIpcTreeEntries); /*0x146e2c*/
  zchange(ipc_tree_entry_zone, 0, 0, 1, 0); /*0x146e3a*/
  ipc_object_zones[0] = zinit(80, 80 * ipc_port_max, 80, 0, aIpcPorts); /*0x146e5e*/
  zchange(ipc_object_zones[0], 0, 0, 1, 0); /*0x146e6c*/
  dword_1F6234 = zinit(28, 28 * ipc_pset_max, 28, 0, aIpcPortSets); /*0x146e93*/
  zchange(dword_1F6234, 0, 0, 1, 0); /*0x146ea1*/
  ipc_space_create_special(&ipc_space_kernel); /*0x146eae*/
  ipc_space_create_special(&ipc_space_reply); /*0x146eb8*/
  ipc_table_init(); /*0x146ebd*/
  ipc_notify_init(); /*0x146ec2*/
  ipc_hash_init(); /*0x146ec7*/
  return ipc_marequest_init(); /*0x146ed3*/
}
