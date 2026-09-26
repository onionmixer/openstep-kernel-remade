/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109820 */

void _pgsignal(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 4);
    while (uVar1 != 0) {
      if ((param_3 == 0) || ((*(byte *)(uVar1 + 0x2b) & 0x40) != 0)) {
        _psignal(uVar1,param_2);
      }
      iVar2 = _get_posix_proc((int)*(short *)(uVar1 + 0x30));
      uVar1 = *(uint *)(iVar2 + 0xc);
    }
  }
  return;
}

