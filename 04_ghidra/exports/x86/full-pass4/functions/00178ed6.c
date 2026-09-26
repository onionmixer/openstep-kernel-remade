/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178ed6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00178ed6(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *unaff_ESI;
  
  while ((int *)*unaff_ESI != unaff_ESI) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    _vm_page_free();
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
  }
  do {
  } while (_vm_object_list_lock != 0);
  LOCK();
  UNLOCK();
  puVar1 = (undefined *)unaff_ESI[2];
  puVar2 = (undefined *)unaff_ESI[3];
  puVar3 = puVar2;
  if (puVar1 != &_vm_object_list) {
    *(undefined **)(puVar1 + 0xc) = puVar2;
    puVar3 = DAT_001f7354;
  }
  DAT_001f7354 = puVar3;
  if (puVar2 != &_vm_object_list) {
    *(undefined **)(puVar2 + 8) = puVar1;
    puVar1 = __vm_object_list;
  }
  __vm_object_list = puVar1;
  __vm_object_count = __vm_object_count + -1;
  LOCK();
  _vm_object_list_lock = 0;
  UNLOCK();
  _zfree(_vm_object_zone);
  return;
}

