
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
