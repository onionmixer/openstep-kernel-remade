/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001096e8 */

int _killpg(pid_t param_1,int param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  if (0x20 < (uint)puVar1[1]) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    return (int)puVar1;
  }
  uVar2 = _killpg1(puVar1[1],*puVar1,0);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

