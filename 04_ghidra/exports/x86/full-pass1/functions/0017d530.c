/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d530 */

bool _vnode_has_page(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_8 [4];
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vnode_has_page__failed_lookup_001e0ea2);
  }
  if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
    iVar1 = FUN_0017cd58(param_1,param_2,1,local_8);
    return iVar1 != 5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vnode_has_page_called_on_non_def_001e0ec0);
}

