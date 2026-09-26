/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119b5c */

void _vfs_putnum(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  if (-1 < param_2) {
    bVar2 = (char)param_2 + (char)(param_2 >> 3) * -8 & 0x1f;
    pbVar1 = (byte *)((param_2 >> 3) + param_1);
    *pbVar1 = *pbVar1 & ((byte)(-2 << bVar2) | (byte)(0xfffffffe >> 0x20 - bVar2));
  }
  return;
}

