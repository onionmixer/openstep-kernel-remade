/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191810 */

void _pmap_page_protect(undefined4 param_1,int param_2)

{
  if (param_2 != 5) {
    if (param_2 < 6) {
      if (param_2 == 1) goto LAB_00191830;
    }
    else if (param_2 == 7) {
      return;
    }
    _pmap_remove_all(param_1);
    return;
  }
LAB_00191830:
  _pmap_copy_on_write(param_1);
  return;
}

