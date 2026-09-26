/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179bbc */

uint __regparm1 _vm_object_page_remove(uint param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_2;
    while (puVar2 = puVar1, param_2 != puVar2) {
      puVar1 = (undefined4 *)puVar2[2];
      param_1 = puVar2[6];
      if ((param_3 <= param_1) && (param_1 < param_4)) {
        _pmap_remove_all(puVar2[9]);
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free(puVar2);
        param_1 = _vm_page_queue_lock;
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
      }
    }
  }
  return param_1;
}

