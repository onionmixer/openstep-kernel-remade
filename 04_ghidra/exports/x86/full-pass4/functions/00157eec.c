/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157eec */

kern_return_t _processor_set_default(host_t host,processor_set_name_t *default_set)

{
  if (host != 0) {
    *default_set = (processor_set_name_t)&_default_pset;
    _pset_reference(&_default_pset);
    return 0;
  }
  return 4;
}

