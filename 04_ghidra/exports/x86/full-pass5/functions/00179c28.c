/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179c28 */

undefined4
_vm_object_coalesce(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                   int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      piVar1 = param_1 + 4;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      _vm_object_collapse(param_1);
      if ((((1 < *(short *)(param_1 + 6)) || (param_1[10] != 0)) || (param_1[8] != 0)) ||
         (param_1[7] != 0)) {
        LOCK();
        param_1[4] = 0;
        UNLOCK();
        return 0;
      }
      if (param_1 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*param_1;
        while (puVar4 = puVar3, param_1 != puVar4) {
          puVar3 = (undefined4 *)puVar4[2];
          if (((uint)(param_3 + param_5) <= (uint)puVar4[6]) &&
             ((uint)puVar4[6] < (uint)(param_3 + param_5 + param_6))) {
            _pmap_remove_all(puVar4[9]);
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free(puVar4);
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
          }
        }
      }
      uVar6 = param_3 + param_5 + param_6;
      if ((uint)param_1[5] < uVar6) {
        param_1[5] = uVar6;
      }
      LOCK();
      param_1[4] = 0;
      UNLOCK();
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

