/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122be8 */

void _arptfree(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _splimp();
  if (param_1[3] != 0) {
    _m_freem(param_1[3]);
  }
  param_1[3] = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  _splx(uVar1);
  return;
}

