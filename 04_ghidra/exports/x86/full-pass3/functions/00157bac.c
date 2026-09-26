/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157bac */

kern_return_t
_host_processor_sets
          (host_priv_t host_priv,processor_set_name_array_t *processor_sets,
          mach_msg_type_number_t *processor_setsCnt)

{
  kern_return_t kVar1;
  processor_set_name_array_t ppVar2;
  processor_set_t pVar3;
  
  if (host_priv == 0) {
    kVar1 = 4;
  }
  else {
    ppVar2 = (processor_set_name_array_t)_kalloc(4);
    if (ppVar2 == (processor_set_name_array_t)0x0) {
      kVar1 = 6;
    }
    else {
      _pset_reference(&_default_pset);
      pVar3 = _convert_pset_name_to_port(&_default_pset);
      *ppVar2 = pVar3;
      *processor_sets = ppVar2;
      *processor_setsCnt = 1;
      kVar1 = 0;
    }
  }
  return kVar1;
}

