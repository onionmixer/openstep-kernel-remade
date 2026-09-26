/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157c98 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00157c98(void)

{
  undefined4 unaff_EBX;
  
  _ipc_kobject_set();
  DAT_001e97b4 = unaff_EBX;
  _ipc_pset_init(&_default_pset);
  _ipc_pset_enable(&_default_pset);
  _ipc_processor_init(_master_processor);
  return;
}

