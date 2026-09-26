/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111c84 */

int _ptsopen(ushort param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((param_1 & 0xff) < 0x20) {
    iVar3 = (short)(param_1 & 0xff) * 0x10;
    if (*(int *)(&DAT_001e56d0 + iVar3) == 0) {
      _lock_write(&_pty_alloc_lock);
      if (*(int *)(&DAT_001e56d0 + iVar3) == 0) {
        pvVar4 = (void *)_kalloc(0x88);
        *(void **)(&DAT_001e56d0 + iVar3) = pvVar4;
        _bzero(pvVar4,0x88);
        pvVar4 = (void *)_kalloc(0x10);
        *(void **)(&DAT_001e56d4 + iVar3) = pvVar4;
        _bzero(pvVar4,0x10);
      }
      _lock_done(&_pty_alloc_lock);
    }
    uVar1 = *(uint *)(&DAT_001e56d0 + iVar3);
    *(ushort *)(&DAT_001e56c8 + iVar3) = param_1;
    if ((*(uint *)(uVar1 + 0x40) & 4) == 0) {
      _ttychars(uVar1);
      *(undefined1 *)(uVar1 + 0x4a) = 0xf;
      *(undefined1 *)(uVar1 + 0x49) = 0xf;
      *(undefined4 *)(uVar1 + 0x3c) = 0;
    }
    else if (((char)*(uint *)(uVar1 + 0x40) < '\0') &&
            (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0)) {
      return 0x10;
    }
    if (*(int *)(uVar1 + 0x24) != 0) {
      *(byte *)(uVar1 + 0x40) = *(byte *)(uVar1 + 0x40) | 0x10;
    }
    if ((param_2 & 4) == 0) {
      while ((*(uint *)(uVar1 + 0x40) & 0x10) == 0) {
        *(uint *)(uVar1 + 0x40) = *(uint *)(uVar1 + 0x40) | 2;
        _sleep(uVar1);
      }
    }
    else {
      *(uint *)(uVar1 + 0x40) = *(uint *)(uVar1 + 0x40) | 0x8000;
    }
    iVar2 = (*(code *)(&_linesw)[*(char *)(uVar1 + 0x47) * 0xc])((int)(short)param_1,uVar1);
    if (iVar2 == 0) {
      (&DAT_001e56cc)[iVar3] = (&DAT_001e56cc)[iVar3] | 1;
    }
    _ptcwakeup(uVar1,3);
  }
  else {
    iVar2 = 6;
  }
  return iVar2;
}

