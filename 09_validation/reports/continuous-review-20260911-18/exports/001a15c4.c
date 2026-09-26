
undefined4 _PCresume(void)

{
  int *piVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = _active_threads;
  iVar5 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar5 == 0) {
    puVar3 = (undefined2 *)_thread_user_state(_active_threads);
  }
  else {
    puVar3 = (undefined2 *)(iVar5 + 0x84);
  }
  piVar1 = *(int **)(*(int *)(iVar6 + 0x28) + 0xec);
  iVar5 = 0;
  if (piVar1 != (int *)0x0) {
    iVar5 = *piVar1;
  }
  if ((iVar5 == 0) || (((*(byte *)(iVar5 + 0x80) & 1) != 0 && ((*(byte *)(iVar5 + 0x6c) & 4) == 0)))
     ) {
    uVar4 = 5;
  }
  else {
    if (*(uint *)(iVar5 + 0x84) < 8) {
      iVar6 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
    }
    else {
      iVar6 = 0;
    }
    *(uint *)(iVar6 + 0x68) = *(uint *)(iVar5 + 100) >> 9 & 1;
    *(uint *)(iVar6 + 0x6c) = *(byte *)(iVar5 + 0x80) >> 2 & 1;
    *(ushort *)(iVar6 + 0x70) = *(ushort *)(iVar5 + 100) & 0x7000;
    _PCscheduleTimers(iVar6);
    *(undefined4 *)(iVar6 + 0x48) = 1;
    *(undefined4 *)(puVar3 + 0x16) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(iVar5 + 0x44);
    *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(iVar5 + 0x48);
    *(undefined4 *)(puVar3 + 0x12) = *(undefined4 *)(iVar5 + 0x4c);
    *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(iVar5 + 0x50);
    *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(iVar5 + 0x54);
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(iVar5 + 0x58);
    *(undefined4 *)(puVar3 + 0x22) = *(undefined4 *)(iVar5 + 0x5c);
    puVar3[0x24] = *(undefined2 *)(iVar5 + 0x60);
    uVar2 = *(uint *)(iVar5 + 100);
    *(uint *)(puVar3 + 0x20) = uVar2;
    *(uint *)(puVar3 + 0x20) = uVar2 & 0x50fd7 | 0x202;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(iVar5 + 0x68);
    puVar3[0x1e] = *(undefined2 *)(iVar5 + 0x6c);
    if ((*(byte *)(iVar5 + 0x80) & 1) == 0) {
      *(uint *)(puVar3 + 0x20) = *(uint *)(puVar3 + 0x20) | 0x20000;
      puVar3[6] = 0;
      puVar3[4] = 0;
      puVar3[2] = 0;
      *puVar3 = 0;
      puVar3[0x28] = *(undefined2 *)(iVar5 + 0x70);
      puVar3[0x26] = *(undefined2 *)(iVar5 + 0x74);
      puVar3[0x2a] = *(undefined2 *)(iVar5 + 0x78);
      puVar3[0x2c] = *(undefined2 *)(iVar5 + 0x7c);
    }
    else {
      puVar3[6] = *(undefined2 *)(iVar5 + 0x70);
      puVar3[4] = *(undefined2 *)(iVar5 + 0x74);
      puVar3[2] = *(undefined2 *)(iVar5 + 0x78);
      *puVar3 = *(undefined2 *)(iVar5 + 0x7c);
    }
    uVar4 = _thread_exception_return();
  }
  return uVar4;
}

