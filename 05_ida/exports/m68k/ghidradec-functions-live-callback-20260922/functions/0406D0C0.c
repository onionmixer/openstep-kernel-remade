
void sub_406D0C0(int *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  pbVar1 = (byte *)*param_1;
  if (_machine_type == '\0') {
    *(byte *)(param_2 + 0x4e) = *(byte *)(param_2 + 0x4e) | 8;
  }
  bVar2 = *(byte *)(param_2 + 0x4e);
  bVar3 = (byte)((((word)(*(byte *)(*param_1 + 8) ^ 4) & 7) >> 2) << 3);
  bVar4 = bVar2 & 0xf7 | bVar3;
  *(byte *)(param_2 + 0x4e) = bVar4;
  if (((byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f)) & pbVar1[2]) == 0) {
    bVar4 = bVar2 & 0xd7 | bVar3;
  }
  else {
    bVar4 = bVar4 | 0x20;
  }
  *(byte *)(param_2 + 0x4e) = bVar4;
  bVar2 = pbVar1[8];
  bVar4 = *(byte *)(param_2 + 0x4e);
  bVar3 = bVar4 & 0x3f | bVar2 << 6;
  *(byte *)(param_2 + 0x4e) = bVar3;
  if ((*pbVar1 & 2) == 0) {
    bVar3 = bVar3 | 0x10;
  }
  else {
    bVar3 = bVar4 & 0x2f | bVar2 << 6;
  }
  *(byte *)(param_2 + 0x4e) = bVar3;
  return;
}

