/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179084 */

undefined4 __regparm1 _vm_object_deactivate_pages(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_2;
  while (param_2 != puVar2) {
    puVar1 = (undefined4 *)puVar2[2];
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    if ((*(byte *)((int)puVar2 + 0x1e) & 1) == 0) {
      _vm_page_deactivate(puVar2);
    }
    param_1 = _vm_page_queue_lock;
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    puVar2 = puVar1;
  }
  return param_1;
}

