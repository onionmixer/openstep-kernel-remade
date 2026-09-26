/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160714 */

undefined4 _sched_usec_elapsed(void)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = _clock_value(1);
  lVar1 = CONCAT44(DAT_001e5e48,DAT_001e5e44);
  if ((DAT_001e5e44 == 0) && (lVar1 = CONCAT44(DAT_001e5e48,DAT_001e5e44), DAT_001e5e48 == 0)) {
    lVar1 = lVar2;
  }
  DAT_001e5e44 = (int)lVar2;
  DAT_001e5e48 = (int)((ulonglong)lVar2 >> 0x20);
  return (int)((((ulonglong)(lVar2 - lVar1) >> 0x20) % 1000 << 0x20 | lVar2 - lVar1 & 0xffffffffU) /
              1000);
}

