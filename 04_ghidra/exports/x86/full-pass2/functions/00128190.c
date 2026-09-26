/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00128190 */

void _ip_freemoptions(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = param_1 + *(int *)(param_1 + 4);
    iVar1 = 0;
    if (*(short *)(iVar2 + 6) != 0) {
      do {
        _in_delmulti(*(undefined4 *)(iVar2 + 8 + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(ushort *)(iVar2 + 6));
    }
    _m_free(param_1);
  }
  return;
}

