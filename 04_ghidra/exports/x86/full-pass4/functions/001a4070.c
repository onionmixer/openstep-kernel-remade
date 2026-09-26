/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4070 */

void FUN_001a4070(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  _objc_msgSend(DAT_001e8684,PTR_s_lock_001f9220);
  piVar3 = DAT_001e867c;
  do {
    if ((int **)piVar3 == &DAT_001e867c) {
LAB_001a40da:
      _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
      return;
    }
    if (*piVar3 == param_3) {
      puVar1 = (undefined4 *)piVar3[5];
      puVar2 = (undefined4 *)piVar3[6];
      puVar4 = &DAT_001e867c;
      if ((int **)puVar1 != &DAT_001e867c) {
        puVar4 = puVar1 + 5;
      }
      puVar4[1] = puVar2;
      puVar4 = &DAT_001e867c;
      if ((int **)puVar2 != &DAT_001e867c) {
        puVar4 = puVar2 + 5;
      }
      *puVar4 = puVar1;
      goto LAB_001a40da;
    }
    piVar3 = (int *)piVar3[5];
  } while( true );
}

