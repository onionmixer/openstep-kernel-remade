/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc184 */

undefined4 _NXCompareMapTables(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == param_2) {
LAB_001cc1c5:
    uVar2 = 1;
  }
  else {
    if (*(int *)(param_2 + 4) == *(int *)(param_1 + 4)) {
      local_8 = _NXInitMapState(param_1);
      do {
        iVar1 = _NXNextMapState(param_1,&local_8,&local_c,local_10);
        if (iVar1 == 0) goto LAB_001cc1c5;
        iVar1 = _NXMapMember(param_2,local_c,local_10);
      } while (iVar1 != -1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

