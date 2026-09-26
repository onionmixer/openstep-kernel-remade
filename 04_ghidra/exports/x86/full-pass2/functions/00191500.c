/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191500 */

undefined4 _pmap_is_modified(uint param_1)

{
  undefined4 uVar1;
  
  if ((_vm_first_phys <= param_1) && (param_1 < _vm_last_phys)) {
    uVar1 = FUN_001916e0(param_1,1);
    return uVar1;
  }
  return 0;
}

