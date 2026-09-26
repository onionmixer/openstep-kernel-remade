/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cc74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 _led_msg(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined1 *)(iVar2 + param_1);
    out(0xcaf - (short)iVar2,*puVar1);
    LOCK();
    _DAT_001e7730 = _DAT_001e7730 + 1;
    UNLOCK();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return *puVar1;
}

