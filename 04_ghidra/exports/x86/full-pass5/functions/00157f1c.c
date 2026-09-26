/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157f1c */

undefined4 _xxx_processor_set_default_priv(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = &_default_pset;
    _pset_reference(&_default_pset);
    return 0;
  }
  return 4;
}

