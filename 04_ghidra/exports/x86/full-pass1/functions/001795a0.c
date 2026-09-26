/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001795a0 */

void _vm_object_shadow(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = _zalloc(_vm_object_zone);
  __vm_object_allocate(param_3,iVar2);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_object_shadow__no_object_for_s_001e0c05);
  }
  *(int *)(iVar2 + 0x20) = iVar1;
  *(undefined4 *)(iVar2 + 0x24) = *param_2;
  *param_2 = 0;
  *param_1 = iVar2;
  return;
}

