/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187400 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _PMConnect(void)

{
  _DAT_001e75bc = (uint)_DAT_00011368;
  _DAT_001e75c0 = (uint)_DAT_0001136a;
  if (_DAT_00011388 != 0) {
    DAT_001e75b8 = 1;
    FUN_001871e8();
    _printf(s_Power_management_is_enabled__001e17d8);
    return 0;
  }
  return 0x3e80086;
}

