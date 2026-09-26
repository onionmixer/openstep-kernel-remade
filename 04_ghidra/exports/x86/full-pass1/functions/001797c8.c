/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001797c8 */

undefined4 _vm_object_cache_clear(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  do {
  } while (_vm_cache_lock != 0);
  LOCK();
  UNLOCK();
  puVar4 = _vm_object_cached_list;
  while( true ) {
    if ((undefined4 **)puVar4 == &_vm_object_cached_list) {
      _vm_object_cached_list = puVar4;
      LOCK();
      _vm_cache_lock = 0;
      UNLOCK();
      return 1;
    }
    LOCK();
    UNLOCK();
    puVar3 = &_vm_object_hashtable + (puVar4[10] & 0x7f) * 2;
    LOCK();
    UNLOCK();
    puVar6 = (undefined4 *)*puVar3;
    _vm_object_cached_list = puVar4;
    if (puVar3 != puVar6) break;
LAB_001798b2:
    LOCK();
    UNLOCK();
    puVar7 = (undefined4 *)0x0;
LAB_001798bc:
    _vm_cache_lock = 0;
    if (puVar4 != puVar7) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_object_cache_clear__I_m_sooo_c_001e0c2f);
    }
    _vm_object_cache_object(puVar4,0);
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    UNLOCK();
    puVar4 = _vm_object_cached_list;
  }
LAB_00179840:
  puVar7 = (undefined4 *)puVar6[2];
  if (puVar7[10] != puVar4[10]) goto LAB_001798ac;
  piVar1 = puVar7 + 4;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(short *)(puVar7 + 6) == 0) {
    puVar3 = (undefined4 *)puVar7[0x13];
    puVar6 = (undefined4 *)puVar7[0x14];
    puVar5 = puVar6;
    if ((undefined4 **)puVar3 != &_vm_object_cached_list) {
      puVar3[0x14] = puVar6;
      puVar5 = DAT_001f6f3c;
    }
    DAT_001f6f3c = puVar5;
    if ((undefined4 **)puVar6 != &_vm_object_cached_list) {
      puVar6[0x13] = puVar3;
      puVar3 = _vm_object_cached_list;
    }
    _vm_object_cached_list = puVar3;
    _vm_object_cached = _vm_object_cached + -1;
  }
  *(short *)(puVar7 + 6) = *(short *)(puVar7 + 6) + 1;
  LOCK();
  puVar7[4] = 0;
  UNLOCK();
  LOCK();
  UNLOCK();
  goto LAB_001798bc;
LAB_001798ac:
  puVar6 = (undefined4 *)*puVar6;
  if (puVar3 == puVar6) goto LAB_001798b2;
  goto LAB_00179840;
}

