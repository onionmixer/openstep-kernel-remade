/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c96fc */

undefined4 FUN_001c96fc(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar2 = _objc_msgSend(param_1,PTR_s_class_001f9234);
  cVar1 = _objc_msgSend(param_3,PTR_s_isKindOf__001f9260,uVar2);
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (*(int *)(param_3 + 8) == *(int *)(param_1 + 8)) {
      iVar3 = *(int *)(param_1 + 8) * 4;
      bVar6 = true;
      pcVar4 = *(char **)(param_1 + 4);
      pcVar5 = *(char **)(param_3 + 4);
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

