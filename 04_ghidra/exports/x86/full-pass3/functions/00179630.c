/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179630 */

int _vm_object_lookup(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  do {
  } while (_vm_cache_lock != 0);
  LOCK();
  UNLOCK();
  puVar3 = (undefined4 *)(&_vm_object_hashtable)[(param_1 & 0x7f) * 2];
  while( true ) {
    if (&_vm_object_hashtable + (param_1 & 0x7f) * 2 == puVar3) {
      LOCK();
      UNLOCK();
      _vm_cache_lock = 0;
      return 0;
    }
    iVar4 = puVar3[2];
    if (*(uint *)(iVar4 + 0x28) == param_1) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  piVar1 = (int *)(iVar4 + 0x10);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(short *)(iVar4 + 0x18) == 0) {
    puVar3 = *(undefined4 **)(iVar4 + 0x4c);
    puVar5 = *(undefined4 **)(iVar4 + 0x50);
    puVar6 = puVar5;
    if ((undefined4 **)puVar3 != &_vm_object_cached_list) {
      puVar3[0x14] = puVar5;
      puVar6 = DAT_001f6f3c;
    }
    DAT_001f6f3c = puVar6;
    if ((undefined4 **)puVar5 != &_vm_object_cached_list) {
      puVar5[0x13] = puVar3;
      puVar3 = _vm_object_cached_list;
    }
    _vm_object_cached_list = puVar3;
    _vm_object_cached = _vm_object_cached + -1;
  }
  *(short *)(iVar4 + 0x18) = *(short *)(iVar4 + 0x18) + 1;
  LOCK();
  *(undefined4 *)(iVar4 + 0x10) = 0;
  UNLOCK();
  LOCK();
  UNLOCK();
  _vm_cache_lock = 0;
  return iVar4;
}

