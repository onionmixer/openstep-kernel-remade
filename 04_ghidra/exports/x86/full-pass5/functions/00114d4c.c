/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114d4c */

void _sofree(uint param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) == 0) && ((*(byte *)(param_1 + 6) & 1) != 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar1 = _soqremque(param_1,0);
      if (iVar1 == 0) {
        iVar1 = _soqremque(param_1,1);
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_sofree_dq_001db2dd);
        }
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    _sbrelease(param_1 + 0x3c);
    _sorflush(param_1);
    _m_free(param_1 & 0xffffff80);
  }
  return;
}

