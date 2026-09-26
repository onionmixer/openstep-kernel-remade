/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108d40 */

undefined4 _kill_tasks(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *set;
  
  uVar4 = _pmap_create(0,0,0,1);
  iVar5 = _vm_map_create(uVar4);
  do {
  } while (_all_psets_lock != 0);
  LOCK();
  UNLOCK();
  puVar3 = _all_psets;
  while (set = puVar3, (undefined4 **)set != &_all_psets) {
    puVar3 = DAT_001e975c;
    if (set != (undefined4 *)&_default_pset) {
      LOCK();
      _all_psets_lock = 0;
      UNLOCK();
      _processor_set_destroy((processor_set_t)set);
      do {
      } while (_all_psets_lock != 0);
      LOCK();
      UNLOCK();
      puVar3 = _all_psets;
    }
  }
  LOCK();
  _all_psets_lock = 0;
  UNLOCK();
  do {
  } while (DAT_001e9768 != 0);
  LOCK();
  DAT_001e9768 = 1;
  UNLOCK();
  while (uVar4 = DAT_001e9768, iVar2 = DAT_001e973c, DAT_001e9744 != 0) {
    _pset_remove_task(&_default_pset,DAT_001e973c);
    iVar1 = *(int *)(iVar2 + 0xc);
    if ((_kernel_map != iVar1) && (iVar5 != iVar1)) {
      *(int *)(iVar2 + 0xc) = iVar5;
      _vm_map_reference(iVar5);
      LOCK();
      DAT_001e9768 = 0;
      UNLOCK();
      _vm_map_remove(iVar1,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18));
      do {
      } while (DAT_001e9768 != 0);
      LOCK();
      DAT_001e9768 = 1;
      UNLOCK();
    }
  }
  LOCK();
  DAT_001e9768 = 0;
  UNLOCK();
  return uVar4;
}

