/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbfb4 */

int * _NXCreateMapTableFromZone
                (int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  piVar3 = (int *)(**(code **)(param_6 + 4))(param_6,0x10);
  if (DAT_001e557c == 0) {
    DAT_001e557c = _NXCreateHashTable(PTR_FUN_001e556c,PTR_FUN_001e5570,PTR__NXNoEffectFree_001e5574
                                      ,DAT_001e5578,0,0);
  }
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 != 0)) {
    __NXLogError("*** NXCreateMapTable: invalid creation parameters\n");
    piVar3 = (int *)0x0;
  }
  else {
    piVar4 = (int *)_NXHashGet(DAT_001e557c,&param_1);
    if (piVar4 == (int *)0x0) {
      piVar4 = _malloc(0x10);
      *piVar4 = param_1;
      piVar4[1] = param_2;
      piVar4[2] = param_3;
      piVar4[3] = param_4;
      _NXHashInsert(DAT_001e557c,piVar4);
    }
    *piVar3 = (int)piVar4;
    piVar3[1] = 0;
    cVar2 = FUN_001cbf14(param_5);
    iVar7 = 1 << (cVar2 + 1U & 0x1f);
    iVar1 = iVar7 + -1;
    piVar3[2] = iVar1;
    puVar5 = (undefined4 *)(**(code **)(param_6 + 4))(param_6,iVar1 * 8);
    puVar6 = puVar5;
    for (iVar7 = iVar7 + -2; iVar7 != -1; iVar7 = iVar7 + -1) {
      *puVar6 = 0xffffffff;
      puVar6[1] = 0;
      puVar6 = puVar6 + 2;
    }
    piVar3[3] = (int)puVar5;
  }
  return piVar3;
}

