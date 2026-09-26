/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ec00 */

undefined4 _mfs_cache_trim(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  while( true ) {
    do {
      puVar3 = _vm_info_queue;
    } while (_vm_info_lock_data != 0);
    LOCK();
    UNLOCK();
    if (_mfs_files_mapped <= _mfs_files_max) break;
    puVar1 = (undefined4 *)_vm_info_queue[10];
    puVar2 = (undefined4 *)_vm_info_queue[0xb];
    puVar4 = puVar2;
    if ((undefined4 **)puVar1 != &_vm_info_queue) {
      puVar1[0xb] = puVar2;
      puVar4 = DAT_001f64d4;
    }
    DAT_001f64d4 = puVar4;
    if ((undefined4 **)puVar2 != &_vm_info_queue) {
      puVar2[10] = puVar1;
      puVar1 = _vm_info_queue;
    }
    _vm_info_queue = puVar1;
    *(byte *)(puVar3 + 0xe) = *(byte *)(puVar3 + 0xe) & 0xfe;
    _mfs_files_mapped = _mfs_files_mapped + -1;
    _vm_info_version = _vm_info_version + 1;
    LOCK();
    UNLOCK();
    LOCK();
    UNLOCK();
    if ((*(byte *)(puVar3 + 0xe) & 1) != 0) {
      puVar1 = (undefined4 *)puVar3[10];
      puVar2 = (undefined4 *)puVar3[0xb];
      puVar4 = puVar2;
      if ((undefined4 **)puVar1 != &_vm_info_queue) {
        puVar1[0xb] = puVar2;
        puVar4 = DAT_001f64d4;
      }
      DAT_001f64d4 = puVar4;
      if ((undefined4 **)puVar2 != &_vm_info_queue) {
        puVar2[10] = puVar1;
        puVar1 = _vm_info_queue;
      }
      _vm_info_queue = puVar1;
      *(byte *)(puVar3 + 0xe) = *(byte *)(puVar3 + 0xe) & 0xfe;
      _mfs_files_mapped = _mfs_files_mapped + -1;
      _vm_info_version = _vm_info_version + 1;
    }
    LOCK();
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_write(puVar3 + 6);
    if (*(short *)(puVar3 + 1) == 0) {
      *(byte *)(puVar3 + 0xe) = *(byte *)(puVar3 + 0xe) & 0xef;
    }
    _mfs_map_remove(puVar3,puVar3[2],puVar3[2] + puVar3[3],1);
    puVar3[3] = 0;
    puVar3[2] = 0;
    iVar5 = 0;
    if (*(short *)(puVar3 + 1) == 0) {
      iVar5 = puVar3[9];
      puVar3[9] = 0;
      if (puVar3[0xc] != 0) {
        _crfree(puVar3[0xc]);
        puVar3[0xc] = 0;
      }
    }
    _lock_done(puVar3 + 6);
    if (iVar5 != 0) {
      _vm_object_deallocate(iVar5);
    }
  }
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  return 1;
}

