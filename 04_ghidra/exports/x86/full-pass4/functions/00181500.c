/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181500 */

undefined4 FUN_00181500(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  
  pcVar2 = (char *)_objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_removeKey__001f92a0,param_3);
  if (pcVar2 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar5 = pcVar2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    _IOFree(pcVar2,~uVar4);
    uVar3 = 1;
  }
  return uVar3;
}

