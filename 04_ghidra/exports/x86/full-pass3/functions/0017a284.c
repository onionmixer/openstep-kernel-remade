/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a284 */

void _vm_pager_put(int *param_1,undefined4 param_2)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_pager_put__null_pager_001e0cbc);
  }
  if (*param_1 == 0) {
    _vnode_pageout(param_2);
  }
  else {
    _device_pageout(param_2);
  }
  return;
}

