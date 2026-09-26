/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117aa0 */

int _shutdown(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _getsock(*puVar1);
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar2 = _soshutdown(*(undefined4 *)(iVar3 + 0x18),puVar1[1]);
    iVar4 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  }
  return iVar4;
}

