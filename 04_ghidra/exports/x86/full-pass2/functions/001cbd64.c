/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbd64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _NXUniqueString(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    _DAT_001e555c = _DAT_001e555c + 1;
    if (DAT_001e5558 == 0) {
      DAT_001e5558 = _NXCreateHashTable(_NXStrHash,_NXStrIsEqual,_NXNoEffectFree,0,0,0);
    }
    iVar1 = _NXHashGet(DAT_001e5558,param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_001cbc80(param_1);
    iVar2 = _NXHashInsert(DAT_001e5558,iVar1);
    if (iVar2 == 0) {
      return iVar1;
    }
    __NXLogError("*** NXUniqueString: invariant broken\n");
  }
  return 0;
}

