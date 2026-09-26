/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179350 */

undefined4 __regparm1
_vm_object_pmap_remove(undefined4 param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar1 = param_2 + 4;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    for (puVar3 = (undefined4 *)*param_2; param_2 != puVar3; puVar3 = (undefined4 *)puVar3[2]) {
      if ((param_3 <= (uint)puVar3[6]) && ((uint)puVar3[6] < param_4)) {
        _pmap_remove_all(puVar3[9]);
      }
    }
    LOCK();
    param_1 = param_2[4];
    param_2[4] = 0;
    UNLOCK();
  }
  return param_1;
}

