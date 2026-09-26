/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001790dc */

undefined4 _vm_object_cache_trim(void)

{
  int iVar1;
  int iVar2;
  
  do {
  } while (_vm_cache_lock != 0);
  LOCK();
  UNLOCK();
  while( true ) {
    iVar1 = _vm_object_cached_list;
    if (_vm_object_cached <= _vm_cache_max) {
      LOCK();
      _vm_cache_lock = 0;
      UNLOCK();
      return 1;
    }
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
    iVar2 = _vm_object_lookup(*(undefined4 *)(_vm_object_cached_list + 0x28));
    if (iVar1 != iVar2) break;
    _vm_object_cache_object(iVar1,0);
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    UNLOCK();
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_object_deactivate__I_m_sooo_c_001e0bb2);
}

