/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a482c */

undefined4
FUN_001a482c(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_c;
  int local_8;
  
  iVar2 = 7;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IOUnit";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    *param_3 = *(undefined4 *)(param_1 + 4);
LAB_001a48d3:
    *param_5 = 1;
    uVar1 = 0;
  }
  else {
    iVar2 = 0xd;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "IOBlockMajor";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      uVar1 = _objc_msgSend(param_1,PTR_s_class_001f9234,&local_8);
      iVar2 = FUN_001a3e30(uVar1);
      if (iVar2 == 0) {
        uVar1 = *(undefined4 *)(local_8 + 8);
LAB_001a48ce:
        *param_3 = uVar1;
        goto LAB_001a48d3;
      }
    }
    else {
      iVar2 = 0x11;
      bVar5 = true;
      pcVar3 = "IOCharacterMajor";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *param_4 == *pcVar3;
        param_4 = param_4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar5);
      if (bVar5) {
        uVar1 = _objc_msgSend(param_1,PTR_s_class_001f9234,&local_c);
        iVar2 = FUN_001a3e30(uVar1);
        if (iVar2 == 0) {
          uVar1 = *(undefined4 *)(local_c + 0xc);
          goto LAB_001a48ce;
        }
      }
    }
    uVar1 = 0xfffffd39;
  }
  return uVar1;
}

