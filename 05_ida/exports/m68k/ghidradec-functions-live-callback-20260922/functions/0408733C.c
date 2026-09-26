
void _snd_stream_enqueue_region(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar1 = *(undefined4 **)((int)param_1 + 0x3a);
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xfd;
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xfb | (byte)(((*(byte *)(param_1 + 0xb) & 3) >> 1) << 2);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xfd |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 7) >> 2) << 1);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xf7 |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 3) >> 1) << 3);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xef |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 0xf) >> 3) << 4);
  *(byte *)((int)param_1 + 0x2d) =
       *(byte *)((int)param_1 + 0x2d) & 0xdf |
       (byte)(((*(byte *)((int)param_1 + 0x2d) & 0x1f) >> 4) << 5);
  uVar3 = ~_page_mask;
  param_1[8] = *param_1 & uVar3;
  param_1[7] = *param_1 & uVar3;
  param_1[4] = *param_1;
  param_1[3] = param_1[4];
  param_1[2] = param_1[1] + *param_1;
  if (param_1[10] == 0) {
    param_1[10] = *(uint *)((int)puVar1 + 0x36);
  }
  if (param_1[9] == 0) {
    param_1[9] = *(uint *)((int)puVar1 + 0x32);
  }
  if (param_1[5] == 0) {
    param_1[5] = *(uint *)((int)puVar1 + 0x2a);
  }
  if (puVar1[7] == 0) {
    puVar4 = puVar1;
    if ((undefined4 **)dword_40C6EB0 != &dword_40C6EAC) {
      dword_40C6EB0[5] = puVar1;
      puVar4 = dword_40C6EAC;
    }
    dword_40C6EAC = puVar4;
    puVar1[6] = dword_40C6EB0;
    puVar1[5] = &dword_40C6EAC;
    dword_40C6EB0 = puVar1;
    uVar5 = _kernel_thread(dword_40C6EB8,sub_408771E);
    puVar1[7] = uVar5;
  }
  _lock_write(puVar1 + 1);
  puVar4 = puVar1 + 3;
  if (puVar4 != (undefined4 *)*puVar4) {
    *(byte *)((int)param_1 + 0x2d) =
         *(byte *)((int)param_1 + 0x2d) & 0xfb | *(byte *)(puVar1[4] + 0x2d) & 4;
  }
  puVar2 = (undefined4 *)puVar1[4];
  if (puVar2 == puVar4) {
    *puVar2 = param_1;
  }
  else {
    *(uint **)((int)puVar2 + 0x32) = param_1;
  }
  *(undefined4 **)((int)param_1 + 0x36) = puVar2;
  *(undefined4 **)((int)param_1 + 0x32) = puVar1 + 3;
  puVar1[4] = param_1;
  _lock_done(puVar1 + 1);
  *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) | 2;
  _thread_wakeup_prim(puVar1,0,0);
  return;
}

