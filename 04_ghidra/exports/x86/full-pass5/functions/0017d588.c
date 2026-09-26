/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d588 */

int _vnode_pager_file_init(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  short *psVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined1 local_84 [4];
  int local_80;
  int local_7c;
  undefined1 local_44 [24];
  uint local_2c;
  
  *param_1 = 0;
  _mfs_uncache(param_2);
  if ((*(byte *)(*param_2 + 0x38) & 0x10) == 0) {
    psVar2 = *(short **)(_active_u + 0x1c);
    (**(code **)(param_2[7] + 0x14))(param_2,local_44,psVar2);
    uVar9 = local_2c;
    if (param_3 < local_2c) {
      _vattr_null(local_44);
      local_2c = param_3;
      iVar5 = (**(code **)(param_2[7] + 0x18))(param_2,local_44,psVar2);
      uVar9 = param_3;
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    *(uint *)(*param_2 + 0x14) = uVar9;
    puVar6 = (undefined4 *)_kalloc(0x40);
    *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;
    puVar6[2] = param_2;
    *psVar2 = *psVar2 + 1;
    *(short **)(*param_2 + 0x30) = psVar2;
    puVar6[3] = 0;
    puVar6[9] = 0;
    puVar6[7] = (param_3 + _page_mask & ~_page_mask) >> ((byte)_page_shift & 0x1f);
    if (param_4 == 0) {
      iVar5 = (**(code **)(*(int *)(param_2[9] + 4) + 0xc))(param_2[9],local_84);
      if (iVar5 != 0) {
        _kfree(puVar6,0x40);
        return iVar5;
      }
      param_4 = local_7c * local_80;
    }
    param_4 = param_4 >> ((byte)_page_shift & 0x1f);
    puVar6[5] = param_4;
    puVar6[6] = param_4;
    iVar5 = puVar6[5] + 7;
    if (iVar5 < 0) {
      iVar5 = puVar6[5] + 0xe;
    }
    uVar7 = _kalloc(iVar5 >> 3);
    puVar6[4] = uVar7;
    iVar5 = 0;
    if (0 < (int)puVar6[5]) {
      do {
        iVar8 = iVar5;
        if (iVar5 < 0) {
          iVar8 = iVar5 + 7;
        }
        bVar3 = (char)iVar5 + (char)(iVar8 >> 3) * -8 & 0x1f;
        pbVar1 = (byte *)((iVar8 >> 3) + puVar6[4]);
        *pbVar1 = *pbVar1 & ((byte)(-2 << bVar3) | (byte)(0xfffffffe >> 0x20 - bVar3));
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)puVar6[5]);
    }
    puVar6[8] = 0xffffffff;
    puVar6[0xb] = 0;
    _lock_init(puVar6 + 0xd,1);
    puVar4 = puVar6;
    if ((undefined4 **)DAT_001e728c != &DAT_001e7288) {
      *DAT_001e728c = puVar6;
      puVar4 = DAT_001e7288;
    }
    DAT_001e7288 = puVar4;
    puVar6[1] = DAT_001e728c;
    *puVar6 = &DAT_001e7288;
    DAT_001e7290 = DAT_001e7290 + 1;
    DAT_001e728c = puVar6;
    puVar6[0xc] = DAT_001e7290;
    *(undefined4 **)(&DAT_001e7294 + DAT_001e7290 * 4) = puVar6;
    *param_1 = puVar6;
    iVar5 = 0;
  }
  else {
    iVar5 = 0x10;
  }
  return iVar5;
}

