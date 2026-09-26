/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179128 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00179128(void)

{
  int iVar1;
  int unaff_EBX;
  
  while( true ) {
    _vm_object_cache_object(unaff_EBX);
    unaff_EBX = _vm_object_cached_list;
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    UNLOCK();
    if (_vm_object_cached <= _vm_cache_max) break;
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
    iVar1 = _vm_object_lookup();
    if (unaff_EBX != iVar1) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_object_deactivate__I_m_sooo_c_001e0bb2);
    }
  }
  LOCK();
  _vm_cache_lock = 0;
  UNLOCK();
  return 1;
}

