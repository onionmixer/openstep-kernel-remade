/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d1e4 */

void _us_spin(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  while (iVar1 = param_1 + -1, iVar2 = _us_spin_us_const, param_1 != 0) {
    do {
      bVar3 = iVar2 != 0;
      param_1 = iVar1;
      iVar2 = iVar2 + -1;
    } while (bVar3);
  }
  return;
}

