/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103ef8 */

int _dup2(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  if (((*puVar1 < *(uint *)(_active_u + 0x15c)) &&
      (iVar4 = *(int *)(*(int *)(_active_u + 0x150) + *puVar1 * 4), iVar4 != 0)) &&
     (iVar4 != -0x10000)) {
    uVar2 = puVar1[1];
    if (0xff < uVar2) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 9;
      return uVar2;
    }
    *(uint *)(DAT_001e875c + 0x60) = uVar2;
    uVar2 = puVar1[1];
    if (*puVar1 == uVar2) {
      return uVar2;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38),uVar2);
    if ((*(int *)(*(int *)(_active_u + 0x150) + *puVar1 * 4) == iVar4) &&
       (iVar3 = *(int *)(*(int *)(_active_u + 0x150) + puVar1[1] * 4), iVar3 != -0x10000)) {
      if (iVar3 != 0) {
        _vno_lockrelease(iVar3);
        if ((*(byte *)(puVar1[1] + *(int *)(_active_u + 0x154)) & 2) != 0) {
          _munmapfd(puVar1[1]);
        }
        _closef(*(undefined4 *)(*(int *)(_active_u + 0x150) + puVar1[1] * 4));
        *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      }
      if (*(int *)(*(int *)(_active_u + 0x150) + *puVar1 * 4) == iVar4) {
        iVar4 = _dupit(puVar1[1],iVar4,(int)*(char *)(*puVar1 + *(int *)(_active_u + 0x154)));
        return iVar4;
      }
    }
  }
  iVar4 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  return iVar4;
}

