/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb020 */

int * _NXCreateHashTableFromZone
                (code *param_1,code *param_2,code *param_3,int param_4,undefined4 param_5,
                int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = param_7;
  piVar1 = (int *)(**(code **)(param_7 + 4))(param_7,0x14);
  if (DAT_001e5554 == 0) {
    FUN_001caf74();
  }
  if (param_1 == (code *)0x0) {
    param_1 = _NXPtrHash;
  }
  if (param_2 == (code *)0x0) {
    param_2 = _NXPtrIsEqual;
  }
  if (param_3 == (code *)0x0) {
    param_3 = _NXNoEffectFree;
  }
  if (param_4 == 0) {
    iVar2 = _NXHashGet(DAT_001e5554,&param_1);
    if (iVar2 == 0) {
      iVar2 = _NXDefaultMallocZone();
      uVar3 = _NXDefaultMallocZone(0x10);
      pvVar4 = (void *)(**(code **)(iVar2 + 4))(uVar3);
      _memmove(pvVar4,&param_1,0x10);
      _NXHashInsert(DAT_001e5554,pvVar4);
      iVar2 = _NXHashGet(DAT_001e5554,&param_1);
      if (iVar2 == 0) {
        pcVar6 = "*** NXCreateHashTable: bug\n";
        goto LAB_001cb0de;
      }
    }
    *piVar1 = iVar2;
    piVar1[1] = 0;
    piVar1[4] = param_6;
    iVar2 = FUN_001caebc(param_5);
    iVar2 = FUN_001caedc(iVar2 + 1);
    piVar1[2] = iVar2;
    iVar5 = _NXZoneCalloc(iVar5,iVar2,8);
    piVar1[3] = iVar5;
  }
  else {
    pcVar6 = "*** NXCreateHashTable: invalid style\n";
LAB_001cb0de:
    __NXLogError(pcVar6);
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

