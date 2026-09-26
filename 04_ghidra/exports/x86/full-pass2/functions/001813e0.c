/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001813e0 */

int FUN_001813e0(int param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_3;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)_IOMalloc(~uVar3);
  pcVar2 = _strcpy(pcVar2,param_3);
  pcVar2 = (char *)_objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_insertKey_value__001f9288,
                                 param_4,pcVar2);
  if (pcVar2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    _IOFree(pcVar2,~uVar3);
  }
  return param_1;
}

