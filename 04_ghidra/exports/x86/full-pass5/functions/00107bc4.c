/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107bc4 */

void _setposix(void)

{
  uint uVar1;
  
  uVar1 = **(uint **)(DAT_001e875c + 0x24);
  if (uVar1 < 2) {
    *(int *)(DAT_001e875c + 0x60) = (int)((char)(*(char *)(*_active_u + 0x16) << 6) >> 7);
    *(byte *)(*_active_u + 0x16) = *(byte *)(*_active_u + 0x16) & 0xfd | ((byte)uVar1 & 1) * '\x02';
    return;
  }
  *(undefined4 *)(DAT_001e875c + 0x60) = 0xffffffff;
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  return;
}

