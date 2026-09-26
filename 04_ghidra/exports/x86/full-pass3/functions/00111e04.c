/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111e04 */

undefined4 _ptsread(byte param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(&DAT_001e56d0 + (uint)param_1 * 0x10);
  pbVar2 = *(byte **)(&DAT_001e56d4 + (uint)param_1 * 0x10);
  uVar5 = 0;
  while ((*pbVar2 & 0x20) != 0) {
    while ((_active_u[0x5a] == iVar1 &&
           (iVar4 = *_active_u, *(short *)(iVar4 + 0x2e) != *(short *)(iVar1 + 0x44)))) {
      if ((*(byte *)(iVar4 + 0x16) & 2) == 0) {
        if ((((*(byte *)(iVar4 + 0x22) & 0x10) != 0) || ((*(byte *)(iVar4 + 0x1e) & 0x10) != 0)) ||
           ((*(byte *)(iVar4 + 0x29) & 0x10) != 0)) {
          return 5;
        }
      }
      else {
        iVar3 = _get_posix_proc((int)*(short *)(iVar4 + 0x30));
        if ((*(byte *)(iVar4 + 0x22) & 0x10) != 0) {
          return 5;
        }
        if ((*(byte *)(iVar4 + 0x1e) & 0x10) != 0) {
          return 5;
        }
        if (*(int *)(*(int *)(iVar3 + 0x10) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal((int)*(short *)(*_active_u + 0x2e),0x15);
      _sleep(0x1e8df0);
    }
    iVar4 = *(int *)(iVar1 + 0xc);
    if (iVar4 != 0) goto joined_r0x00111f0b;
    if ((*(byte *)(iVar1 + 0x41) & 0x20) != 0) {
      if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
        return 0x23;
      }
      return 0xb;
    }
    _sleep(iVar1 + 0xc);
  }
  if (*(int *)(iVar1 + 0x24) != 0) {
    uVar5 = (*(code *)(&PTR__ttread_001daff0)[*(char *)(iVar1 + 0x47) * 0xc])(iVar1,param_2);
  }
  goto LAB_00111f7a;
joined_r0x00111f0b:
  if ((iVar4 < 2) || (*(int *)(param_2 + 0x14) < 1)) goto LAB_00111f39;
  iVar4 = param_2;
  iVar3 = _getc((FILE *)(iVar1 + 0xc));
  iVar4 = _ureadc(iVar3,iVar4);
  if (-1 < iVar4) {
    iVar4 = *(int *)(iVar1 + 0xc);
    goto joined_r0x00111f0b;
  }
  uVar5 = 0xe;
LAB_00111f39:
  if (*(int *)(iVar1 + 0xc) == 1) {
    _getc((FILE *)(iVar1 + 0xc));
  }
  if (*(int *)(iVar1 + 0xc) != 0) {
    return uVar5;
  }
LAB_00111f7a:
  _ptcwakeup(iVar1,2);
  return uVar5;
}

