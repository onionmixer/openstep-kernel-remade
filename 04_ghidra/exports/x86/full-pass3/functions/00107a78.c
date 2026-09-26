/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107a78 */

undefined4 _setprivexec(void)

{
  int *piVar1;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  *(int *)(*(int *)(_active_threads + 0x84) + 0x60) =
       (int)((char)(*(char *)(*_active_u + 0x16) << 7) >> 7);
  *(byte *)(*_active_u + 0x16) = *(byte *)(*_active_u + 0x16) & 0xfe | *piVar1 != 0;
  return 0;
}

