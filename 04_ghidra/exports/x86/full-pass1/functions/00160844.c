/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160844 */

/* WARNING: Removing unreachable block (ram,0x00160874) */

void _microtime(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = _splusclock();
  uVar3 = _clock_value(0);
  if (((uVar3 < CONCAT44(DAT_001df220,DAT_001df21c)) &&
      (DAT_001df220 - (int)(uVar3 >> 0x20) == (uint)(DAT_001df21c < (uint)uVar3))) &&
     (DAT_001df21c - (uint)uVar3 < 1000000000)) {
    uVar3 = CONCAT44(DAT_001df220,DAT_001df21c);
  }
  uVar2 = (uint)(uVar3 >> 0x20);
  DAT_001df21c = (uint)uVar3;
  DAT_001df220 = uVar2;
  _splx(uVar1);
  uVar3 = (ulonglong)uVar2 % 1000000000 << 0x20 | uVar3 & 0xffffffff;
  param_1[1] = (int)(uVar3 % 1000000000);
  *param_1 = (int)(uVar3 / 1000000000);
  param_1[1] = (int)param_1[1] / 1000;
  return;
}

