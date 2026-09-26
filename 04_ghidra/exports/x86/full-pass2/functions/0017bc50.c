/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017bc50 */

undefined4 FUN_0017bc50(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  
  bVar2 = true;
  local_c = 0;
  if (param_1 != (int *)0x0) {
    piVar4 = param_1 + 4;
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar3 == 1);
LAB_0017bc8c:
    piVar4 = (int *)*param_1;
    if (param_1 != piVar4) {
      do {
        if ((param_2 <= (uint)piVar4[6]) && ((uint)piVar4[6] < param_3)) {
          iVar3 = FUN_0017bacc(param_1,piVar4);
          if (iVar3 == 1) {
            bVar2 = false;
          }
          else if ((iVar3 != 0) && (iVar3 == 2)) goto LAB_0017bc8c;
        }
        piVar4 = (int *)piVar4[2];
        if (param_1 == piVar4) break;
      } while( true );
    }
    param_3 = param_3 - param_2;
    uVar1 = param_1[5];
    if ((uVar1 != 0) && (uVar1 < param_3)) {
      param_3 = uVar1;
    }
    iVar3 = FUN_0017bc50(param_1[8],param_2 + param_1[9],param_3 + param_2 + param_1[9]);
    if (iVar3 != 0) {
      local_c = 5;
    }
    LOCK();
    param_1[4] = 0;
    UNLOCK();
    _thread_wakeup_prim(param_1,0,0);
    if ((local_c == 5) || (!bVar2)) {
      return 5;
    }
  }
  return 0;
}

