/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174744 */

int __vm_map_entry_create(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  iVar2 = _zalloc(uVar1);
  if (iVar2 != 0) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_map_entry_create_001e0ab0);
}

