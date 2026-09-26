/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d790 */

int _stat(char *param_1,stat *param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = _stat1(*(undefined4 *)(DAT_001e875c + 0x24),1);
  iVar2 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  return iVar2;
}

