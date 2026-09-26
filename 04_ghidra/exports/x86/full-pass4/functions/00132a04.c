/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132a04 */

int FUN_00132a04(int param_1,char *param_2,int param_3,char *param_4,undefined4 param_5)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  int local_50;
  undefined1 local_4c [36];
  undefined1 local_28 [36];
  
  iVar1 = 2;
  bVar4 = true;
  pcVar2 = param_2;
  pcVar3 = &DAT_001dcb48;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 3;
    bVar4 = true;
    pcVar2 = param_2;
    pcVar3 = &DAT_001dcb4a;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      iVar1 = 2;
      bVar4 = true;
      pcVar2 = param_4;
      pcVar3 = &DAT_001dcb4d;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (!bVar4) {
        iVar1 = 3;
        bVar4 = true;
        pcVar2 = param_4;
        pcVar3 = &DAT_001dcb4f;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *pcVar2 == *pcVar3;
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar4);
        if (!bVar4) {
          _rlock(*(undefined4 *)(param_1 + 0x30));
          _dnlc_remove(param_1,param_2);
          _dnlc_remove(param_3,param_4);
          if (param_3 != param_1) {
            _rlock(*(undefined4 *)(param_3 + 0x30));
          }
          _setdiropargs(local_4c,param_2,param_1);
          _setdiropargs(local_28,param_4,param_3);
          iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0xb,_xdr_rnmargs,
                           local_4c,_xdr_enum,&local_50,param_5);
          *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
          *(undefined4 *)(*(int *)(param_3 + 0x30) + 0xc0) = 0;
          _runlock(*(undefined4 *)(param_1 + 0x30));
          if (param_3 != param_1) {
            _runlock(*(undefined4 *)(param_3 + 0x30));
          }
          if (iVar1 != 0) {
            return iVar1;
          }
          if (local_50 != 0x46) {
            return local_50;
          }
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
          _btrash(param_3);
          _nfs_invalidate_caches(param_3);
          return 0x46;
        }
      }
    }
  }
  return 0x16;
}

