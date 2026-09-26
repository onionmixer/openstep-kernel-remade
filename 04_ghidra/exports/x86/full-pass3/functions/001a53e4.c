/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a53e4 */

int FUN_001a53e4(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  char *pcVar5;
  
  iVar2 = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
  uVar4 = 0xffffffff;
  pcVar5 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  if (0x1000 < (int)uVar4) {
    uVar4 = 0x1000;
  }
  pvVar3 = (void *)_IOMalloc(uVar4);
  _bcopy(param_3,pvVar3,uVar4 - 1);
  *(undefined1 *)((int)pvVar3 + (uVar4 - 1)) = 0;
  *(void **)(iVar2 + 4) = pvVar3;
  return iVar2;
}

