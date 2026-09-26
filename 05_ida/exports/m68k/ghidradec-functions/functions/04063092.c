
int _vnode_pager_file_init(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  sword *psVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined auStack_7e [4];
  int iStack_7a;
  int iStack_76;
  undefined auStack_3e [20];
  uint uStack_2a;
  
  *param_1 = 0;
  _mfs_uncache(param_2);
  if ((*(byte *)(*param_2 + 0x34) & 8) == 0) {
    psVar2 = *(sword **)(_active_u + 0x1a);
    (**(code **)(param_2[7] + 0x14))(param_2,auStack_3e,psVar2);
    uVar7 = uStack_2a;
    if (param_3 < uStack_2a) {
      _vattr_null(auStack_3e);
      uStack_2a = param_3;
      iVar3 = (**(code **)(param_2[7] + 0x18))(param_2,auStack_3e,psVar2);
      uVar7 = param_3;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    *(uint *)(*param_2 + 0x14) = uVar7;
    puVar4 = (undefined4 *)_kalloc(0x3c);
    *(sword *)((int)param_2 + 6) = *(sword *)((int)param_2 + 6) + 1;
    puVar4[2] = param_2;
    *psVar2 = *psVar2 + 1;
    *(sword **)(*param_2 + 0x2c) = psVar2;
    puVar4[3] = 0;
    puVar4[9] = 0;
    puVar4[7] = (~_page_mask & _page_mask + param_3) >> (_page_shift & 0x3f);
    if (param_4 == 0) {
      iVar3 = (**(code **)(*(int *)(param_2[9] + 4) + 0xc))(param_2[9],auStack_7e);
      if (iVar3 != 0) {
        _kfree(puVar4,0x3c);
        return iVar3;
      }
      param_4 = iStack_7a * iStack_76;
    }
    param_4 = param_4 >> (_page_shift & 0x3f);
    puVar4[5] = param_4;
    puVar4[6] = param_4;
    iVar3 = puVar4[5] + 7;
    if (iVar3 < 0) {
      iVar3 = puVar4[5] + 0xe;
    }
    uVar5 = _kalloc(iVar3 >> 3);
    puVar4[4] = uVar5;
    iVar3 = 0;
    if (0 < (int)puVar4[5]) {
      do {
        iVar6 = iVar3;
        if (iVar3 < 0) {
          iVar6 = iVar3 + 7;
        }
        pbVar1 = (byte *)(puVar4[4] + (iVar6 >> 3));
        *pbVar1 = ~(byte)(1 << (iVar3 + (iVar6 >> 3) * -8 & 0x3fU)) & *pbVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)puVar4[5]);
    }
    puVar4[8] = 0xffffffff;
    puVar4[0xb] = 0;
    _lock_init(puVar4 + 0xd,1);
    *dword_40B4DF8 = puVar4;
    puVar4[1] = dword_40B4DF8;
    *puVar4 = &dword_40B4DF4;
    iVar6 = dword_40B4DFC;
    iVar3 = dword_40B4DFC + 1;
    dword_40B4DF8 = puVar4;
    dword_40B4DFC = dword_40B4DFC + 1;
    puVar4[0xc] = iVar3;
    (&dword_40B4E04)[iVar6] = puVar4;
    *param_1 = puVar4;
    iVar3 = 0;
  }
  else {
    iVar3 = 0x10;
  }
  return iVar3;
}
