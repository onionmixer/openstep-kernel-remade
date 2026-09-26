
undefined4 sub_4032872(uint *param_1,uint param_2,uint param_3,int *param_4,int *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  uint uStack_8;
  
  param_2 = param_2 / _page_size;
  param_3 = param_3 / *param_1;
  bVar4 = *(byte *)(param_1[3] + 3 + param_2 * 4);
  if ((bVar4 & 0xf0) == 0) {
    sub_403272A(param_1,param_2,8,0);
    if (param_1[7] <= param_2) {
      dword_40B35EA = param_2 + 1;
      param_1[7] = dword_40B35EA;
    }
  }
  else {
    sub_403272A(param_1,*(uint *)(param_1[3] + param_2 * 4) >> 8,bVar4 >> 4,bVar4 & 0xf);
  }
  uVar3 = param_1[8];
  if ((param_1[0xb] / _page_size == uVar3) || (*(uint *)((int)param_1 + 0x3e) / _page_size == uVar3)
     ) {
    pbVar5 = (byte *)(uVar3 + param_1[5]);
    bVar4 = *pbVar5;
    if (bVar4 != 0) {
      uVar2 = (1 << (param_3 & 0x3f)) - 1;
      uVar3 = 0;
      if (-param_3 != -9) {
        do {
          if (uVar2 == (uVar2 & bVar4)) {
            *pbVar5 = ~(byte)(uVar2 << (uVar3 & 0x3f)) & *pbVar5;
            goto loc_4032956;
          }
          bVar4 = bVar4 >> 1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < -param_3 + 9);
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
loc_4032956:
    if (-1 < (int)uVar3) {
      uStack_8 = param_1[8];
      dword_40B35DE = dword_40B35DE + 1;
      goto loc_4032980;
    }
  }
  uVar3 = sub_40327F0(param_1,param_3,&uStack_8);
  if ((int)uVar3 < 0) {
    return 0;
  }
  dword_40B35E2 = dword_40B35E2 + 1;
loc_4032980:
  if ((int)uVar3 < 0) {
    return 0;
  }
  *(uint *)(param_1[3] + param_2 * 4) =
       CONCAT31((int3)uStack_8,*(undefined *)(param_1[3] + 3 + param_2 * 4));
  puVar1 = (uint *)(param_1[3] + 3 + param_2 * 4);
  *puVar1 = *puVar1 & 0xf0ffffff | (uVar3 & 0xf) << 0x18;
  puVar1 = (uint *)(param_1[3] + 3 + param_2 * 4);
  *puVar1 = *puVar1 & 0xfffffff | param_3 << 0x1c;
  *param_4 = _page_size * uStack_8;
  *param_5 = *param_1 * uVar3;
  if (_page_size / *param_1 != param_3) {
    param_1[8] = uStack_8;
  }
  if (unk_40B35E6 < uStack_8) {
    unk_40B35E6 = uStack_8;
  }
  return 1;
}
