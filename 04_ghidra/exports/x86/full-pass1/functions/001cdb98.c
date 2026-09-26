/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdb98 */

int _method_getSizeOfArguments(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  for (pcVar1 = (char *)FUN_001cd9a4(*(undefined4 *)(param_1 + 4)); (byte)(*pcVar1 - 0x30U) < 10;
      pcVar1 = pcVar1 + 1) {
    iVar2 = (int)*pcVar1 + iVar2 * 10 + -0x30;
  }
  return iVar2;
}

