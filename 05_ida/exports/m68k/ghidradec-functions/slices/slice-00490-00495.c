/* GHIDRADEC_FUNCTION index=490 start=0x40175e0 */

void _vfs_putnum(int param_1,uint param_2)

{
  byte *pbVar1;
  
  if (-1 < (int)param_2) {
    pbVar1 = (byte *)(param_1 + ((int)param_2 >> 3));
    *pbVar1 = *pbVar1 & ~('\x01' << (param_2 & 7));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=491 start=0x4017608 */

uint * _bread(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  _bstats = _bstats + 1;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aBreadSize0);
  }
  puVar1 = (uint *)_getblk(param_1,param_2,param_3);
  if ((*puVar1 & 2) == 0) {
    *puVar1 = *puVar1 | 1;
    if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
      _panic(&aBread);
    }
    (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
    *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    _biowait(puVar1);
  }
  else {
    dword_40B6B50 = dword_40B6B50 + 1;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=492 start=0x401769a */

uint * _breada(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
              undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  dword_40B6B54 = dword_40B6B54 + 1;
  puVar3 = (uint *)0x0;
  iVar1 = _incore(param_1,param_2);
  if (iVar1 == 0) {
    puVar3 = (uint *)_getblk(param_1,param_2,param_3);
    if ((*puVar3 & 2) == 0) {
      *puVar3 = *puVar3 | 1;
      if ((int)puVar3[6] < (int)puVar3[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(&aBreada);
      }
      (**(code **)(*(int *)(puVar3[0x10] + 0x1c) + 0x54))(puVar3);
      *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    }
    else {
      dword_40B6B58 = dword_40B6B58 + 1;
    }
  }
  if ((param_4 != 0) && (iVar1 = _incore(param_1,param_4), iVar1 == 0)) {
    puVar2 = (uint *)_getblk(param_1,param_4,param_5);
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 0x101;
      if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(aBreadrabp);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
      *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
    }
    else {
      _brelse(puVar2);
      dword_40B6B5C = dword_40B6B5C + 1;
    }
  }
  if (puVar3 == (uint *)0x0) {
    puVar3 = (uint *)_bread(param_1,param_2,param_3);
  }
  else {
    _biowait(puVar3);
  }
  return puVar3;
}
/* GHIDRADEC_FUNCTION index=493 start=0x40178a2 */

void _vnReadAhead(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  
  if (param_2 != 0) {
    iVar1 = _incore(param_1,param_2);
    if (iVar1 == 0) {
      puVar2 = (uint *)_getblk(param_1,param_2,param_3);
      if ((*puVar2 & 2) == 0) {
        *puVar2 = *puVar2 | 0x101;
        if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(aBreadrabp);
        }
        (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))(puVar2);
        *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
      }
      else {
        _brelse(puVar2);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=494 start=0x4017930 */

int _breadDirect(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  undefined auStack_48 [3];
  byte bStack_45;
  sword sStack_2c;
  int iStack_20;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  iVar1 = _incore(param_1,param_3);
  if (iVar1 == 0) {
    sub_40177C6(param_1,param_2,param_3,param_4,auStack_48);
    _vnReadAhead(param_1,param_6,param_7);
    _biowait(auStack_48);
    if ((bStack_45 & 4) == 0) {
      sub_401787A(auStack_48);
      *param_8 = 0;
      param_4 = param_4 - iStack_20;
    }
    else {
      *param_8 = (int)sStack_2c;
      param_4 = param_4 - iStack_20;
      sub_401787A(auStack_48);
    }
  }
  else {
    iVar1 = _breada(param_1,param_3,param_4,param_6,param_7);
    if ((*(byte *)(iVar1 + 3) & 4) == 0) {
      _copy_to_phys(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(param_2 + 0x22),param_5);
      *param_8 = 0;
      _brelse(iVar1);
      param_4 = param_4 - *(int *)(iVar1 + 0x28);
    }
    else {
      _brelse(iVar1);
      *param_8 = (int)*(sword *)(iVar1 + 0x1c);
      param_4 = 0;
    }
  }
  return param_4;
}

