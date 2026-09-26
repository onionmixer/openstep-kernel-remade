/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c454 */

int _ipc_port_timestamp(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_timestamp_data;
  do {
  } while (_ipc_port_timestamp_lock_data != 0);
  LOCK();
  UNLOCK();
  _ipc_port_timestamp_data = _ipc_port_timestamp_data + 1;
  LOCK();
  _ipc_port_timestamp_lock_data = 0;
  UNLOCK();
  return iVar1;
}

