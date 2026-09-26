/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125d18 */

uint _iptime(void)

{
  uint uVar1;
  int local_c;
  int local_8;
  
  _microtime(&local_c);
  uVar1 = local_8 / 1000 + (local_c % 0x15180) * 1000;
  return uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 * 0x1000000;
}

