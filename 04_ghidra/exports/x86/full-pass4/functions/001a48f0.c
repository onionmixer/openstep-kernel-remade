/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a48f0 */

undefined4 FUN_001a48f0(int param_1,undefined4 param_2,char *param_3,char *param_4,uint *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  char *local_c;
  uint local_8;
  
  local_8 = *param_5;
  if (local_8 == 0) {
    local_8 = 0x200;
  }
  iVar3 = 0xc;
  bVar7 = true;
  pcVar5 = param_4;
  pcVar6 = "IOClassName";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    uVar2 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_name_001f9228);
    local_c = (char *)_objc_msgSend(uVar2);
  }
  else {
    iVar3 = 0xd;
    bVar7 = true;
    pcVar5 = param_4;
    pcVar6 = "IODeviceName";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      local_c = (char *)(param_1 + 8);
    }
    else {
      iVar3 = 0xd;
      bVar7 = true;
      pcVar5 = "IODeviceKind";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *param_4 == *pcVar5;
        param_4 = param_4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        return 0xfffffd39;
      }
      local_c = (char *)(param_1 + 0xa8);
    }
  }
  uVar4 = 0xffffffff;
  pcVar5 = local_c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4 - 1;
  if (local_8 <= uVar4) {
    uVar4 = local_8 - 1;
  }
  *param_5 = uVar4 + 1;
  _strncpy(param_3,local_c,uVar4);
  param_3[uVar4] = '\0';
  return 0;
}

