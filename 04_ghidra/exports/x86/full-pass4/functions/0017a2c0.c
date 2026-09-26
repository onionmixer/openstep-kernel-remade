/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a2c0 */

void _vm_pager_deallocate(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_pager_deallocate__null_pager_001e0cd5);
  }
  if (*param_1 == 0) {
    _vnode_dealloc(param_1);
  }
  else {
    _device_dealloc(param_1);
  }
  return;
}

