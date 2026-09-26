
void _vfs_putnum(int param_1,uint param_2)

{
  byte *pbVar1;
  
  if (-1 < (int)param_2) {
    pbVar1 = (byte *)(param_1 + ((int)param_2 >> 3));
    *pbVar1 = *pbVar1 & ~('\x01' << (param_2 & 7));
  }
  return;
}

