
void _munmapfd(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + *(int *)(_active_u + 0x14a));
  *pbVar1 = *pbVar1 & 0xfd;
  return;
}
