/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca960 */

undefined4 * FUN_001ca960(undefined4 param_1)

{
  undefined4 *puVar1;
  
  do {
  } while (DAT_001e5534 != 0);
  LOCK();
  DAT_001e5534 = 1;
  UNLOCK();
  puVar1 = &DAT_001e551c;
  do {
    if (puVar1[4] == 0) {
      puVar1[4] = param_1;
      goto LAB_001ca9bc;
    }
    puVar1 = (undefined4 *)puVar1[5];
  } while (puVar1 != (undefined4 *)0x0);
  puVar1 = _calloc(0x18,1);
  puVar1[4] = param_1;
  puVar1[5] = DAT_001e5530;
  DAT_001e5530 = puVar1;
LAB_001ca9bc:
  LOCK();
  DAT_001e5534 = 0;
  UNLOCK();
  return puVar1;
}

