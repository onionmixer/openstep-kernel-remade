/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144d38 */

int FUN_00144d38(int param_1,char *param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 0x30);
  iVar3 = *(int *)(param_3 + 0x30);
  iVar4 = _iaccess(iVar2,0x80);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = _dirlook(iVar2,param_2,&local_8);
  if (iVar4 != 0) {
    return iVar4;
  }
  _iunlock(local_8);
  if (((((*(byte *)(iVar2 + 0x65) & 2) != 0) &&
       (sVar1 = *(short *)(*(int *)(_active_u + 0x1c) + 2), sVar1 != 0)) &&
      (*(short *)(iVar2 + 0x68) != sVar1)) && (*(short *)(local_8 + 0x68) != sVar1)) {
    iVar4 = 1;
    goto LAB_00144e38;
  }
  iVar4 = 2;
  bVar7 = true;
  pcVar5 = param_2;
  pcVar6 = &DAT_001de51f;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (!bVar7) {
    iVar4 = 3;
    bVar7 = true;
    pcVar5 = param_2;
    pcVar6 = &DAT_001de521;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if ((!bVar7) && (iVar2 != local_8)) {
      iVar4 = _direnter(iVar3,param_4,2,iVar2,local_8,0,0);
      if (iVar4 == 0) {
        iVar4 = _dirremove(iVar2,param_2,local_8,0);
        if (iVar4 != 2) goto LAB_00144e38;
      }
      else if (iVar4 != -1) goto LAB_00144e38;
      iVar4 = 0;
      goto LAB_00144e38;
    }
  }
  iVar4 = 0x16;
LAB_00144e38:
  if ((*(ushort *)(iVar2 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar2 + 0x44) = *(ushort *)(iVar2 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar2 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar2 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(iVar2 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(iVar2 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      *(undefined4 *)(iVar2 + 0x84) = _iuniqtime;
    }
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xb9;
  }
  if ((*(ushort *)(iVar3 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar3 + 0x44) = *(ushort *)(iVar3 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
    }
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xb9;
  }
  _irele(local_8);
  return iVar4;
}

