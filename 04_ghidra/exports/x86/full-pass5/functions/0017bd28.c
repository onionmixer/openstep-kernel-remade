/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017bd28 */

void _useracc(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_3 == 1) {
    uVar1 = 1;
  }
  _vm_map_check_protection
            (*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),~_page_mask & param_1,
             param_1 + param_2 + _page_mask & ~_page_mask,uVar1);
  return;
}

