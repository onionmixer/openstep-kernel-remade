/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a308 */

void _vm_pager_has_page(int *param_1,undefined4 param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    _vnode_has_page(param_1,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_pager_has_page_001e0cf5);
}

