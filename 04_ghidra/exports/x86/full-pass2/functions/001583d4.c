/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001583d4 */

void _ipc_kobject_destroy(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 8);
  if (uVar1 == 9) {
    _vm_object_pager_wakeup(param_1);
    return;
  }
  if (uVar1 < 10) {
    if (uVar1 != 8) {
      return;
    }
    _vm_object_destroy(param_1);
    return;
  }
  if (uVar1 != 0x11) {
    return;
  }
  _netipc_ignore(0,param_1);
  return;
}

