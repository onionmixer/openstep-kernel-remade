/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4730 */

undefined4 FUN_001a4730(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  uVar5 = 0xffffffff;
  pcVar2 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)_IOMalloc(~uVar5 + 7);
  if (pcVar2 != (char *)0x0) {
    _strcpy(pcVar2,param_3);
    _strcat(pcVar2,"Version");
    iVar3 = _objc_getClass(pcVar2);
    _IOFree(pcVar2,~uVar5 + 7);
    if (iVar3 != 0) {
      uVar5 = 0xffffffff;
      pcVar2 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char *)_IOMalloc(~uVar5 + 0x13);
      if (pcVar2 != (char *)0x0) {
        pcVar7 = "driverKitVersionFor";
        pcVar8 = pcVar2;
        for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar8 = pcVar8 + 4;
        }
        _strcat(pcVar2,param_3);
        uVar4 = _sel_getUid(pcVar2);
        cVar1 = _objc_msgSend(iVar3,PTR_s_respondsTo__001f9464,uVar4);
        if (cVar1 == '\0') {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = _objc_msgSend(iVar3,PTR_s_perform__001f9cc8,uVar4);
        }
        _IOFree(pcVar2,~uVar5 + 0x13);
        return uVar4;
      }
    }
  }
  return 0xffffffff;
}

