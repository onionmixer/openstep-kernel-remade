/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5828 */

void FUN_001a5828(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = param_3;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  sVar2 = ~uVar3 - 1;
  if (0x17 < (int)sVar2) {
    sVar2 = 0x17;
  }
  _strncpy((char *)(param_1 + 0x120),param_3,sVar2);
  *(undefined1 *)(param_1 + 0x137) = 0;
  return;
}

