/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001805a8 */

int FUN_001805a8(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    _objc_msgSend(param_1,PTR_s__detachInterruptSources_001f92e4);
    _ipc_port_release_send(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return param_1;
}

