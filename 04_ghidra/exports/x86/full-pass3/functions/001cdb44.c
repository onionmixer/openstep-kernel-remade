/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdb44 */

int _method_getNumberOfArguments(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  for (pcVar2 = (char *)FUN_001cd9a4(*(undefined4 *)(param_1 + 4)); (byte)(*pcVar2 - 0x30U) < 10;
      pcVar2 = pcVar2 + 1) {
  }
  cVar1 = *pcVar2;
  while (cVar1 != '\0') {
    pcVar2 = (char *)FUN_001cd9a4(pcVar2);
    if (*pcVar2 != '-') goto LAB_001cdb81;
    do {
      pcVar2 = pcVar2 + 1;
LAB_001cdb81:
    } while ((byte)(*pcVar2 - 0x30U) < 10);
    iVar3 = iVar3 + 1;
    cVar1 = *pcVar2;
  }
  return iVar3;
}

