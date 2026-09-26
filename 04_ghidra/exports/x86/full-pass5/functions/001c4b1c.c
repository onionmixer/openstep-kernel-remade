/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4b1c */

undefined4 FUN_001c4b1c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  
  iVar2 = *(int *)(param_1 + 0x214);
  puVar3 = (undefined4 *)_objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  iVar4 = _objc_msgSend(param_1,PTR_s_displayModes_001f95f8);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    _bzero(puVar3 + 8,0x40);
    iVar8 = iVar2 * 0x88;
    pcVar6 = (char *)((undefined4 *)(iVar8 + iVar4) + 8);
    uVar7 = 0xffffffff;
    pcVar9 = pcVar6;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    _strncpy((char *)(puVar3 + 8),pcVar6,~uVar7 - 1);
    *puVar3 = *(undefined4 *)(iVar8 + iVar4);
    puVar3[1] = *(undefined4 *)(iVar4 + 4 + iVar8);
    puVar3[2] = *(undefined4 *)(iVar4 + 8 + iVar8);
    puVar3[3] = *(undefined4 *)(iVar4 + 0xc + iVar8);
    puVar3[4] = *(undefined4 *)(iVar4 + 0x10 + iVar8);
    puVar3[6] = *(undefined4 *)(iVar4 + 0x18 + iVar8);
    puVar3[7] = *(undefined4 *)(iVar4 + 0x1c + iVar8);
    puVar3[0x19] = *(undefined4 *)(iVar4 + 100 + iVar8);
    puVar3[0x1e] = *(undefined4 *)(iVar4 + 0x78 + iVar8);
    puVar3[0x1f] = *(undefined4 *)(iVar4 + 0x7c + iVar8);
    puVar3[0x1b] = *(undefined4 *)(iVar4 + 0x6c + iVar8);
    puVar3[0x1a] = *(undefined4 *)(iVar4 + 0x68 + iVar8);
    puVar3[0x1d] = *(undefined4 *)(iVar4 + 0x74 + iVar8);
    puVar3[0x20] = *(undefined4 *)(iVar4 + 0x80 + iVar8);
    iVar4 = *(int *)(iVar4 + 0x60 + iVar8);
    if (iVar4 == 0) {
      if (puVar3[6] == 1) {
        puVar3[0x18] = 0x10;
      }
      else {
        puVar3[0x18] = 2;
      }
    }
    else {
      puVar3[0x18] = iVar4;
    }
    *(int *)(param_1 + 0x210) = iVar2;
    uVar5 = 1;
  }
  return uVar5;
}

