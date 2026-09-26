
void sub_406DCC0(int param_1,undefined *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                int param_6)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  
  pbVar2 = param_2 + 10;
  _bzero(pbVar2,9);
  sub_406E234(param_1,param_3,pbVar2);
  bVar1 = *pbVar2;
  *pbVar2 = bVar1 & 0x7f;
  bVar3 = (byte)((*(uint *)(param_1 + 0x182) & 1) << 6);
  *pbVar2 = bVar1 & 0x3f | bVar3;
  bVar4 = 5;
  if (param_6 != 0) {
    bVar4 = 6;
  }
  *pbVar2 = bVar4 | bVar1 & 0x20 | bVar3;
  *(uint *)(param_2 + 0xb) =
       *(uint *)(param_2 + 0xb) & 0xfbffffff | ((byte)param_2[0xd] & 1) << 0x1a;
  param_2[0xf] = *(undefined *)(param_1 + 0x18a);
  param_2[0x10] =
       param_2[0xe] +
       (char)((param_4 + -1 + *(uint *)(param_1 + 0x186)) / *(uint *)(param_1 + 0x186)) + -1;
  param_2[0x11] = *(undefined *)(param_1 + 400);
  param_2[0x12] = 0xff;
  *param_2 = *(undefined *)(param_1 + 0x17d);
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 9;
  *(undefined4 *)(param_2 + 0x1e) = param_5;
  *(int *)(param_2 + 0x22) = param_4;
  *(undefined4 *)(param_2 + 0x36) = 7;
  if (param_6 == 0) {
    *(uint *)(param_2 + 0x3a) = *(uint *)(param_2 + 0x3a) & 0xfffffffd;
  }
  else {
    *(uint *)(param_2 + 0x3a) = *(uint *)(param_2 + 0x3a) | 2;
  }
  return;
}

