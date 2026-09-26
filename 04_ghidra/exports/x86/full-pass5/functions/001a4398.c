/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4398 */

void FUN_001a4398(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  
  if (param_3 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x58) = 0;
  }
  else {
    uVar2 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    sVar3 = ~uVar2 - 1;
    if (0x4f < (int)sVar3) {
      sVar3 = 0x4f;
    }
    _strncpy((char *)(param_1 + 0x58),param_3,sVar3);
    *(undefined1 *)(sVar3 + 0x58 + param_1) = 0;
  }
  return;
}

