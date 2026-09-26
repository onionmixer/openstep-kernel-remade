/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119e00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _breadDirect(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                undefined4 param_7,int *param_8)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint local_48;
  int local_44;
  undefined *local_40;
  undefined4 local_34;
  undefined4 local_30;
  short local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  int local_24;
  int local_20;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  iVar1 = _incore(param_1,param_3);
  if (iVar1 == 0) {
    local_8 = 0;
    FUN_0011b244(&local_48,param_1);
    local_2a = *(undefined2 *)(param_1 + 0x2c);
    local_48 = 0x2000001;
    local_24 = param_3;
    local_30 = _page_size;
    local_34 = _page_size;
    local_2c = 0;
    local_20 = 0;
    local_28 = *(undefined4 *)(param_2 + 0x24);
    local_c = 0;
    *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
    uVar3 = (param_3 >> 3) + param_1 & 0xf;
    local_40 = &_bufhash + uVar3 * 0xc;
    local_44 = (&DAT_001e8884)[uVar3 * 3];
    *(uint **)((&DAT_001e8884)[uVar3 * 3] + 8) = &local_48;
    (&DAT_001e8884)[uVar3 * 3] = &local_48;
    (**(code **)(*(int *)(local_8 + 0x1c) + 0x54))(&local_48);
    if ((param_6 != 0) && (iVar1 = _incore(param_1,param_6), iVar1 == 0)) {
      puVar4 = (uint *)_getblk(param_1,param_6,param_7);
      if ((*puVar4 & 2) == 0) {
        *puVar4 = *puVar4 | 0x101;
        if ((int)puVar4[6] < (int)puVar4[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_breadrabp_001db579);
        }
        (**(code **)(*(int *)(puVar4[0x10] + 0x1c) + 0x54))(puVar4);
        *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      }
      else {
        _brelse(puVar4);
      }
    }
    _biowait(&local_48);
    if ((local_48 & 4) == 0) {
      *(int *)(local_40 + 4) = local_44;
      *(undefined **)(local_44 + 8) = local_40;
      FUN_0011b26c(&local_48);
      *param_8 = 0;
      param_4 = param_4 - local_20;
    }
    else {
      *param_8 = (int)local_2c;
      param_4 = param_4 - local_20;
      *(int *)(local_40 + 4) = local_44;
      *(undefined **)(local_44 + 8) = local_40;
      FUN_0011b26c(&local_48);
    }
  }
  else {
    _DAT_001e99c8 = _DAT_001e99c8 + 1;
    puVar4 = (uint *)0x0;
    iVar1 = _incore(param_1,param_3);
    if (iVar1 == 0) {
      puVar4 = (uint *)_getblk(param_1,param_3,param_4);
      if ((*puVar4 & 2) == 0) {
        *puVar4 = *puVar4 | 1;
        if ((int)puVar4[6] < (int)puVar4[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_breada_001db568);
        }
        (**(code **)(*(int *)(puVar4[0x10] + 0x1c) + 0x54))(puVar4);
        *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      }
      else {
        _DAT_001e99cc = _DAT_001e99cc + 1;
      }
    }
    if ((param_6 != 0) && (iVar1 = _incore(param_1,param_6), iVar1 == 0)) {
      puVar2 = (uint *)_getblk(param_1,param_6,param_7);
      if ((*puVar2 & 2) == 0) {
        *puVar2 = *puVar2 | 0x101;
        if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_breadrabp_001db56f);
        }
        (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
        *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      }
      else {
        _brelse(puVar2);
        _DAT_001e99d0 = _DAT_001e99d0 + 1;
      }
    }
    if (puVar4 == (uint *)0x0) {
      __bstats = __bstats + 1;
      if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bread__size_0_001db554);
      }
      puVar4 = (uint *)_getblk(param_1,param_3,param_4);
      if ((*puVar4 & 2) == 0) {
        *puVar4 = *puVar4 | 1;
        if ((int)puVar4[6] < (int)puVar4[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_bread_001db562);
        }
        (**(code **)(*(int *)(puVar4[0x10] + 0x1c) + 0x54))(puVar4);
        *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
        _biowait(puVar4);
      }
      else {
        _DAT_001e99c4 = _DAT_001e99c4 + 1;
      }
    }
    else {
      _biowait(puVar4);
    }
    if ((*puVar4 & 4) == 0) {
      _copy_to_phys(puVar4[8],*(undefined4 *)(param_2 + 0x24),param_5);
      *param_8 = 0;
      _brelse(puVar4);
      param_4 = param_4 - puVar4[10];
    }
    else {
      _brelse(puVar4);
      *param_8 = (int)(short)puVar4[7];
      param_4 = 0;
    }
  }
  return param_4;
}

