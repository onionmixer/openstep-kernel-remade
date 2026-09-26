/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139b28 */

undefined4 FUN_00139b28(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (DAT_001e5a30 == 0) {
    DAT_001e5a30 = 1;
    puVar2 = &_stable;
    do {
      for (puVar1 = (undefined4 *)*puVar2; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        if ((-1 < *(char *)(puVar1 + 2)) && (puVar1[0xb] == 3)) {
          _bflush(puVar1 + 1,0xffffffff,0xffffffff);
        }
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 < &_rablock);
    DAT_001e5a30 = 0;
  }
  return 0;
}

