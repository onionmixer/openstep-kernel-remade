/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019152c */

void _pmap_clear_reference(uint param_1)

{
  if ((_vm_first_phys <= param_1) && (param_1 < _vm_last_phys)) {
    FUN_0019157c(param_1,2);
  }
  return;
}

