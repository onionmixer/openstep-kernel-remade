/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018494c */

void _IOInitDDM(int param_1)

{
  if (DAT_001e7584 == 0) {
    DAT_001f74c4 = _IOMalloc(param_1 * 0x24);
    _uxprGlobal = param_1;
    DAT_001e7580 = param_1 * 0x24 + -0x24 + DAT_001f74c4;
    _IOClearDDM();
    _xpr_lock = 0;
    DAT_001e7584 = 1;
  }
  return;
}

