/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001057f0 */

void _create_unix_stack(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint local_8;
  
  *(int *)(*_active_u + 0x84) = param_2;
  uVar1 = _active_u[0x9f] + _page_mask & ~_page_mask;
  local_8 = param_2 - uVar1 & ~_page_mask;
  _vm_map_find(param_1,0,0,&local_8,uVar1,0);
  return;
}

