/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab12c */

undefined4 FUN_001ab12c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  
  iVar1 = _objc_msgSend(param_3,PTR_s_configTable_001f9cdc);
  if (iVar1 == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_unit_001f9c28);
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
    _IOLog("%s: couldn\'t get Instance%d.table\n",uVar2);
    uVar2 = 1;
  }
  else {
    pcVar3 = (char *)_objc_msgSend(iVar1,PTR_s_valueForStringKey__001f9308,"Ring Speed");
    iVar5 = 2;
    iVar4 = 0;
    bVar10 = true;
    pcVar6 = pcVar3;
    pcVar8 = "4";
    do {
      pcVar7 = pcVar6;
      pcVar9 = pcVar8;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar9 = pcVar8 + 1;
      pcVar7 = pcVar6 + 1;
      bVar10 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar7;
      pcVar8 = pcVar9;
    } while (bVar10);
    if (!bVar10) {
      iVar4 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar9[-1];
    }
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 300) = 4;
    }
    else {
      iVar4 = 3;
      bVar10 = true;
      pcVar6 = pcVar3;
      pcVar8 = "16";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar10);
      if (bVar10) {
        *(undefined4 *)(param_1 + 300) = 0x10;
      }
      else {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s: invalid ring speed in Instance.table\n",uVar2);
        *(undefined4 *)(param_1 + 300) = 0x10;
      }
    }
    _objc_msgSend(iVar1,PTR_s_freeString__001f9314,pcVar3);
    uVar2 = _objc_msgSend(iVar1,PTR_s_valueForStringKey__001f9308,"Node Address");
    _objc_msgSend(iVar1,PTR_s_freeString__001f9314,uVar2);
    pcVar3 = (char *)_objc_msgSend(iVar1,PTR_s_valueForStringKey__001f9308,"16Mb Early Token");
    iVar5 = 4;
    iVar4 = 0;
    bVar10 = true;
    pcVar6 = pcVar3;
    pcVar8 = "YES";
    do {
      pcVar7 = pcVar6;
      pcVar9 = pcVar8;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar9 = pcVar8 + 1;
      pcVar7 = pcVar6 + 1;
      bVar10 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar7;
      pcVar8 = pcVar9;
    } while (bVar10);
    if (!bVar10) {
      iVar4 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar9[-1];
    }
    if (iVar4 == 0) {
      *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) | 2;
    }
    else {
      *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) & 0xfd;
    }
    _objc_msgSend(iVar1,PTR_s_freeString__001f9314,pcVar3);
    pcVar3 = (char *)_objc_msgSend(iVar1,PTR_s_valueForStringKey__001f9308,"Auto Recovery");
    iVar5 = 4;
    iVar4 = 0;
    bVar10 = true;
    pcVar6 = pcVar3;
    pcVar8 = "YES";
    do {
      pcVar7 = pcVar6;
      pcVar9 = pcVar8;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar9 = pcVar8 + 1;
      pcVar7 = pcVar6 + 1;
      bVar10 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar7;
      pcVar8 = pcVar9;
    } while (bVar10);
    if (!bVar10) {
      iVar4 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar9[-1];
    }
    if (iVar4 == 0) {
      *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) | 4;
    }
    else {
      *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) & 0xfb;
    }
    _objc_msgSend(iVar1,PTR_s_freeString__001f9314,pcVar3);
    *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) | 8;
    *(undefined4 *)(param_1 + 0x134) = 0x1fa4;
    *(undefined4 *)(param_1 + 0x130) = 8;
    *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) | 0x20;
    _ipforwarding = 0;
    uVar2 = 0;
  }
  return uVar2;
}

