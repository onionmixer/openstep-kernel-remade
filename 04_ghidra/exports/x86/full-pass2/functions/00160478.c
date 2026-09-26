/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160478 */

void _ns_hardclock_init(void)

{
  _ns_per_tick = (int)(1000000000 / (longlong)_hz);
  DAT_001f6534 = _ns_per_tick >> 0x1f;
  _hardclock_init(_ns_per_tick,DAT_001f6534);
  return;
}

