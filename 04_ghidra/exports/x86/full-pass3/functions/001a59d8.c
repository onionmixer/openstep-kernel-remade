/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a59d8 */

undefined4 FUN_001a59d8(int param_1,undefined4 param_2,uint *param_3,char *param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_48;
  int local_44;
  undefined *local_40;
  uint local_3c [14];
  
  local_48 = *param_5;
  if (local_48 == 0) {
    local_48 = 0x200;
  }
  iVar2 = 0xc;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IODiskStats";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    local_3c[0] = *(uint *)(param_1 + 0x13c);
    local_3c[1] = *(undefined4 *)(param_1 + 0x140);
    local_3c[2] = *(undefined4 *)(param_1 + 0x144);
    local_3c[3] = *(undefined4 *)(param_1 + 0x148);
    local_3c[4] = *(undefined4 *)(param_1 + 0x14c);
    local_3c[5] = *(undefined4 *)(param_1 + 0x150);
    local_3c[6] = *(undefined4 *)(param_1 + 0x154);
    local_3c[7] = *(undefined4 *)(param_1 + 0x158);
    local_3c[8] = *(undefined4 *)(param_1 + 0x15c);
    local_3c[9] = *(undefined4 *)(param_1 + 0x160);
    local_3c[10] = *(undefined4 *)(param_1 + 0x164);
    local_3c[0xb] = *(undefined4 *)(param_1 + 0x168);
    local_3c[0xc] = *(undefined4 *)(param_1 + 0x16c);
    local_3c[0xd] = *(undefined4 *)(param_1 + 0x170);
    *param_5 = 0;
    iVar2 = 0;
    do {
      if (*param_5 == local_48) {
        return 0;
      }
      param_3[iVar2] = local_3c[iVar2];
      *param_5 = *param_5 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xe);
  }
  else {
    iVar2 = 10;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "IOIsADisk";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 0x12;
      bVar5 = true;
      pcVar3 = param_4;
      pcVar4 = "IOIsAPhysicalDisk";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        *param_5 = 1;
        *param_3 = (uint)(*(char *)(param_1 + 0x116) != '\0');
        return 0;
      }
      local_44 = param_1;
      local_40 = PTR_s_IODevice_001fa108;
      uVar1 = _objc_msgSendSuper(&local_44,PTR_s_getIntValues_forParameter_count__001f9528,param_3,
                                 param_4,param_5);
      return uVar1;
    }
    *param_5 = 0;
  }
  return 0;
}

