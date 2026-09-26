
void sub_403272A(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_2 + *(int *)(param_1 + 0x14));
  *pbVar1 = (byte)((1 << (param_3 & 0x3f)) + -1 << (param_4 & 0x3f)) | *pbVar1;
  return;
}
