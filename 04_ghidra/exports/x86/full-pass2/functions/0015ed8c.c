/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ed8c */

undefined4 _mfs_cache_clear(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  do {
  } while (_vm_info_lock_data != 0);
  LOCK();
  UNLOCK();
  puVar1 = _vm_info_queue;
  iVar5 = _vm_info_version;
  while (iVar6 = iVar5, puVar4 = puVar1, (undefined4 **)puVar4 != &_vm_info_queue) {
    if (*(short *)(puVar4 + 1) == 0) {
      LOCK();
      UNLOCK();
      LOCK();
      UNLOCK();
      if ((*(byte *)(puVar4 + 0xe) & 1) != 0) {
        puVar1 = (undefined4 *)puVar4[10];
        puVar2 = (undefined4 *)puVar4[0xb];
        puVar3 = puVar2;
        if ((undefined4 **)puVar1 != &_vm_info_queue) {
          puVar1[0xb] = puVar2;
          puVar3 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar3;
        if ((undefined4 **)puVar2 != &_vm_info_queue) {
          puVar2[10] = puVar1;
          puVar1 = _vm_info_queue;
        }
        _vm_info_queue = puVar1;
        *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
      }
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(puVar4 + 6);
      if (*(short *)(puVar4 + 1) == 0) {
        *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xef;
      }
      _mfs_map_remove(puVar4,puVar4[2],puVar4[2] + puVar4[3],1);
      puVar4[3] = 0;
      puVar4[2] = 0;
      iVar5 = 0;
      if (*(short *)(puVar4 + 1) == 0) {
        iVar5 = puVar4[9];
        puVar4[9] = 0;
        if (puVar4[0xc] != 0) {
          _crfree(puVar4[0xc]);
          puVar4[0xc] = 0;
        }
      }
      _lock_done(puVar4 + 6);
      if (iVar5 != 0) {
        _vm_object_deallocate(iVar5);
      }
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
    }
    puVar1 = _vm_info_queue;
    iVar5 = _vm_info_version;
    if (iVar6 == _vm_info_version) {
      puVar1 = (undefined4 *)puVar4[10];
      iVar5 = iVar6;
    }
  }
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  return 1;
}

