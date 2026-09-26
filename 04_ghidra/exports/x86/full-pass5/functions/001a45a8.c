/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a45a8 */

undefined4
FUN_001a45a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,char param_9
            )

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = _objc_msgSend(param_3,PTR_s_configTable_001f9cdc,PTR_s_valueForStringKey__001f9308,
                        "Block Major");
  pcVar3 = (char *)_objc_msgSend(uVar2);
  if (pcVar3 == (char *)0x0) {
    iVar5 = -1;
  }
  else {
    iVar5 = 0;
    cVar1 = *pcVar3;
    while ((cVar1 != '\0' && ((byte)(*pcVar3 - 0x30U) < 10))) {
      iVar5 = (int)*pcVar3 + iVar5 * 10 + -0x30;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  iVar4 = _IOAddToBdevswAt(iVar5,param_4,param_5,param_6,param_7,param_8,(int)param_9);
  if (iVar4 < 0) {
    if (iVar5 < 0) {
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: could not add to bdevsw table at any major\n",uVar2);
    }
    else {
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar5);
      _IOLog("%s: could not add to bdevsw table at major %d\n",uVar2);
    }
    uVar2 = 0;
  }
  else {
    _objc_msgSend(param_1,PTR_s_setBlockMajor__001f9cd4,iVar4);
    uVar2 = 1;
  }
  return uVar2;
}

