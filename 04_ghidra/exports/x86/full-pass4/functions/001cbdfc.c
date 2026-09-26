/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbdfc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _NXUniqueStringNoCopy(undefined4 param_1)

{
  _DAT_001e555c = _DAT_001e555c + 1;
  if (DAT_001e5558 == 0) {
    DAT_001e5558 = _NXCreateHashTable(0x1cbb2c,0x1cbb94,0x1cbc00,0,0,0);
  }
  _NXHashInsertIfAbsent(DAT_001e5558,param_1);
  return;
}

