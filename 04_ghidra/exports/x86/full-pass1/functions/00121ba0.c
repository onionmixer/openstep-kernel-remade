/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121ba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtfree(uint param_1)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_rtfree_001db950);
  }
  *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + -1;
  if ((*(uint *)(param_1 + 0x24) & 0xffff0001) == 0) {
    __rttrash = __rttrash + -1;
    _m_free(param_1 & 0xffffff80);
  }
  return;
}

