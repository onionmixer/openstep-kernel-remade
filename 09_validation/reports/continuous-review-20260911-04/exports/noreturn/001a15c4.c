
undefined4 _PCresume(void)

{
  int *piVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = _active_threads;
  iVar4 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar4 == 0) {
    puVar3 = (undefined2 *)_thread_user_state(_active_threads);
  }
  else {
    puVar3 = (undefined2 *)(iVar4 + 0x84);
  }
  piVar1 = *(int **)(*(int *)(iVar5 + 0x28) + 0xec);
  iVar4 = 0;
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
  }
  if ((iVar4 != 0) && (((*(byte *)(iVar4 + 0x80) & 1) == 0 || ((*(byte *)(iVar4 + 0x6c) & 4) != 0)))
     ) {
    if (*(uint *)(iVar4 + 0x84) < 8) {
      iVar5 = iVar4 + 0x88 + *(uint *)(iVar4 + 0x84) * 0x84;
    }
    else {
      iVar5 = 0;
    }
    *(uint *)(iVar5 + 0x68) = *(uint *)(iVar4 + 100) >> 9 & 1;
    *(uint *)(iVar5 + 0x6c) = *(byte *)(iVar4 + 0x80) >> 2 & 1;
    *(ushort *)(iVar5 + 0x70) = *(ushort *)(iVar4 + 100) & 0x7000;
    _PCscheduleTimers(iVar5);
    *(undefined4 *)(iVar5 + 0x48) = 1;
    *(undefined4 *)(puVar3 + 0x16) = *(undefined4 *)(iVar4 + 0x40);
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(iVar4 + 0x44);
    *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(iVar4 + 0x48);
    *(undefined4 *)(puVar3 + 0x12) = *(undefined4 *)(iVar4 + 0x4c);
    *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(iVar4 + 0x50);
    *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(iVar4 + 0x54);
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(iVar4 + 0x58);
    *(undefined4 *)(puVar3 + 0x22) = *(undefined4 *)(iVar4 + 0x5c);
    puVar3[0x24] = *(undefined2 *)(iVar4 + 0x60);
    uVar2 = *(uint *)(iVar4 + 100);
    *(uint *)(puVar3 + 0x20) = uVar2;
    *(uint *)(puVar3 + 0x20) = uVar2 & 0x50fd7 | 0x202;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(iVar4 + 0x68);
    puVar3[0x1e] = *(undefined2 *)(iVar4 + 0x6c);
    if ((*(byte *)(iVar4 + 0x80) & 1) == 0) {
      *(uint *)(puVar3 + 0x20) = *(uint *)(puVar3 + 0x20) | 0x20000;
      puVar3[6] = 0;
      puVar3[4] = 0;
      puVar3[2] = 0;
      *puVar3 = 0;
      puVar3[0x28] = *(undefined2 *)(iVar4 + 0x70);
      puVar3[0x26] = *(undefined2 *)(iVar4 + 0x74);
      puVar3[0x2a] = *(undefined2 *)(iVar4 + 0x78);
      puVar3[0x2c] = *(undefined2 *)(iVar4 + 0x7c);
    }
    else {
      puVar3[6] = *(undefined2 *)(iVar4 + 0x70);
      puVar3[4] = *(undefined2 *)(iVar4 + 0x74);
      puVar3[2] = *(undefined2 *)(iVar4 + 0x78);
      *puVar3 = *(undefined2 *)(iVar4 + 0x7c);
    }
                    /* WARNING: Subroutine does not return */
    _thread_exception_return();
  }
  return 5;
}

