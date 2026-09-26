
void sub_406E234(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 / *(uint *)(param_1 + 0x18c);
  *(char *)(param_3 + 2) = (char)(uVar1 / *(byte *)(param_1 + 0x16c));
  *(char *)(param_3 + 3) = (char)(uVar1 % (uint)*(byte *)(param_1 + 0x16c));
  *(char *)(param_3 + 4) = (char)(param_2 % *(uint *)(param_1 + 0x18c)) + '\x01';
  return;
}
