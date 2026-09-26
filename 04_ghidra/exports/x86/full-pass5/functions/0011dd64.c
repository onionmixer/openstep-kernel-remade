/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dd64 */

mode_t _umask(mode_t param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(DAT_001e875c + 0x24);
  *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(_active_u + 0x16e);
  iVar2 = _active_u;
  *(ushort *)(_active_u + 0x16e) = *(ushort *)*puVar1 & 0xfff;
  return (mode_t)iVar2;
}

