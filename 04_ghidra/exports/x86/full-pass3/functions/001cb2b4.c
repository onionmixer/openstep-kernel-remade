/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb2b4 */

undefined4 _NXCompareHashTables(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined8 local_c;
  
  if (param_1 == param_2) {
LAB_001cb301:
    uVar3 = 1;
  }
  else {
    iVar1 = _NXCountHashTable(param_1);
    iVar2 = _NXCountHashTable(param_2);
    if (iVar1 == iVar2) {
      local_c = _NXInitHashState(param_1);
      do {
        iVar1 = _NXNextHashState(param_1,&local_c,&local_10);
        if (iVar1 == 0) goto LAB_001cb301;
        iVar1 = _NXHashMember(param_2,local_10);
      } while (iVar1 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

