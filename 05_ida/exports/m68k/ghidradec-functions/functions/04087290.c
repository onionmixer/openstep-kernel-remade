
void _snd_stream_queue_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  *param_1 = param_2;
  puVar1 = param_1 + 3;
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  _lock_init(param_1 + 1,1);
  *(undefined4 *)((int)param_1 + 0x26) = 0;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0x1f;
  param_1[7] = 0;
  *(undefined4 *)((int)param_1 + 0x3a) = param_3;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xef;
  param_1[8] = 0;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfb;
  *(undefined4 *)((int)param_1 + 0x2e) = 4;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xf7;
  return;
}
