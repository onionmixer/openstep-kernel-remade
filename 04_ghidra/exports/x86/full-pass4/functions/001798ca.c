/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001798ca */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001798ca(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_ESI;
  
  while( true ) {
    _vm_object_cache_object(unaff_ESI);
    unaff_ESI = _vm_object_cached_list;
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    UNLOCK();
    if ((undefined4 **)_vm_object_cached_list == &_vm_object_cached_list) {
      LOCK();
      _vm_cache_lock = 0;
      UNLOCK();
      return 1;
    }
    LOCK();
    UNLOCK();
    puVar3 = &_vm_object_hashtable + (_vm_object_cached_list[10] & 0x7f) * 2;
    LOCK();
    UNLOCK();
    puVar5 = (undefined4 *)*puVar3;
    if (puVar3 != puVar5) break;
LAB_001798b2:
    LOCK();
    UNLOCK();
    puVar6 = (undefined4 *)0x0;
LAB_001798bc:
    _vm_cache_lock = 0;
    if (unaff_ESI != puVar6) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_object_cache_clear__I_m_sooo_c_001e0c2f);
    }
  }
LAB_00179840:
  puVar6 = (undefined4 *)puVar5[2];
  if (puVar6[10] != _vm_object_cached_list[10]) goto LAB_001798ac;
  piVar1 = puVar6 + 4;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(short *)(puVar6 + 6) == 0) {
    puVar3 = (undefined4 *)puVar6[0x13];
    puVar5 = (undefined4 *)puVar6[0x14];
    puVar4 = puVar5;
    if ((undefined4 **)puVar3 != &_vm_object_cached_list) {
      puVar3[0x14] = puVar5;
      puVar4 = DAT_001f6f3c;
    }
    DAT_001f6f3c = puVar4;
    if ((undefined4 **)puVar5 != &_vm_object_cached_list) {
      puVar5[0x13] = puVar3;
      puVar3 = _vm_object_cached_list;
    }
    _vm_object_cached_list = puVar3;
    _vm_object_cached = _vm_object_cached + -1;
  }
  *(short *)(puVar6 + 6) = *(short *)(puVar6 + 6) + 1;
  LOCK();
  puVar6[4] = 0;
  UNLOCK();
  LOCK();
  UNLOCK();
  goto LAB_001798bc;
LAB_001798ac:
  puVar5 = (undefined4 *)*puVar5;
  if (puVar3 == puVar5) goto LAB_001798b2;
  goto LAB_00179840;
}

