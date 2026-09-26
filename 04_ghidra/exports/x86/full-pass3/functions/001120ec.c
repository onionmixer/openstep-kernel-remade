/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001120ec */

undefined4 _ptcopen(byte param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  
  if (param_1 < 0x20) {
    iVar3 = (short)(ushort)param_1 * 0x10;
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
    iVar3 = *(int *)(&DAT_001e56d0 + iVar3);
    if (*(int *)(iVar3 + 0x24) == 0) {
      *(code **)(iVar3 + 0x24) = _ptsstart;
      (*(code *)(&PTR__ttymodem_001db00c)[*(char *)(iVar3 + 0x47) * 0xc])(iVar3,1);
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffbfffff | 0x10;
      puVar1 = *(undefined4 **)(&DAT_001e56d4 + (uint)param_1 * 0x10);
      *puVar1 = 0;
      *(undefined1 *)(puVar1 + 3) = 0;
      *(undefined1 *)((int)puVar1 + 0xd) = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}

