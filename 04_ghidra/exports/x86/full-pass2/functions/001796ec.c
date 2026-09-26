/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001796ec */

uint _vm_object_enter(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    param_2 = param_2 & 0x7f;
    puVar1 = &_vm_object_hashtable + param_2 * 2;
    puVar3 = (undefined4 *)_zalloc(_object_hash_zone);
    puVar3[2] = param_1;
    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | 8;
    do {
    } while (_vm_cache_lock != 0);
    LOCK();
    _vm_cache_lock = 1;
    UNLOCK();
    puVar2 = (undefined4 *)(&DAT_001f6f54)[param_2 * 2];
    if (puVar1 == puVar2) {
      *puVar1 = puVar3;
    }
    else {
      *puVar2 = puVar3;
    }
    puVar3[1] = puVar2;
    *puVar3 = puVar1;
    (&DAT_001f6f54)[param_2 * 2] = puVar3;
    param_2 = _vm_cache_lock;
    LOCK();
    _vm_cache_lock = 0;
    UNLOCK();
  }
  return param_2;
}

