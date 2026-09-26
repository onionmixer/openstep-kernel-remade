/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157c0c */

kern_return_t
_host_processor_set_priv(host_priv_t host_priv,processor_set_name_t set_name,processor_set_t *set)

{
  if ((host_priv != 0) && (set_name != 0)) {
    *set = set_name;
    _pset_reference(set_name);
    return 0;
  }
  *set = 0;
  return 4;
}

