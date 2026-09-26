/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a4f0 */

void FUN_0017a4f0(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
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
    for (puVar3 = (undefined4 *)*param_1; param_1 != puVar3; puVar3 = (undefined4 *)puVar3[2]) {
      if ((param_2 <= (uint)puVar3[6]) && ((uint)puVar3[6] < param_3)) {
        _vm_policy_apply(param_1,puVar3,param_4);
      }
    }
    param_3 = param_3 - param_2;
    uVar4 = param_1[5];
    if ((uVar4 != 0) && (uVar4 < param_3)) {
      param_3 = uVar4;
    }
    FUN_0017a4f0(param_1[8],param_2 + param_1[9],param_3 + param_2 + param_1[9],param_4);
    LOCK();
    param_1[4] = 0;
    UNLOCK();
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}

