/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108a48 */

int _getrlimit(int param_1,rlimit *param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  int iVar3;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  if (5 < *puVar1) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    return (int)puVar1;
  }
  uVar2 = _copyout(_active_u + 0x264 + *puVar1 * 8,puVar1[1],8);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

