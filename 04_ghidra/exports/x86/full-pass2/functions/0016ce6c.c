/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ce6c */

void _kern_serv_log(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)*param_1;
  if ((param_2 <= piVar2[0xc]) && (piVar2[9] != 0)) {
    uVar4 = _splhigh();
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    puVar3 = (undefined4 *)piVar2[10];
    piVar2[10] = piVar2[10] + 0x20;
    if (piVar2[0xb] == piVar2[10]) {
      piVar2[10] = piVar2[10] + -0x20;
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      _splx(uVar4);
    }
    else {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      _splx(uVar4);
      *puVar3 = param_3;
      puVar3[1] = param_4;
      puVar3[2] = param_5;
      puVar3[3] = param_6;
      puVar3[4] = param_7;
      puVar3[5] = param_8;
      uVar4 = _event_get();
      puVar3[6] = uVar4;
      puVar3[7] = param_2;
      if (piVar2[6] != 0) {
        _kern_serv_callout(param_1,FUN_0016cf28,piVar2);
      }
    }
  }
  return;
}

