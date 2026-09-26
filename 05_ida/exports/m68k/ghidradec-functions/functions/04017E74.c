
undefined4 _brealloc(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_1[5] == param_2) {
    uVar3 = 1;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x200) == 0) {
      if ((int)param_2 < (int)param_1[5]) {
        if ((uVar2 & 0x20000) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aBrealloc);
        }
      }
      else {
        *param_1 = uVar2 & 0xfffffffd;
        uVar2 = param_1[0x10];
        if (uVar2 != 0) {
          iVar4 = (**(code **)(*(int *)(uVar2 + 0x1c) + 0x80))(uVar2);
          if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aCouldnTDetermi);
          }
          uVar2 = param_1[9];
          uVar5 = uVar2;
          if ((int)uVar2 < 0) {
            uVar5 = uVar2 + 7;
          }
          iVar1 = (param_1[0x10] + ((int)uVar5 >> 3) & 0xf) * 0xc;
loc_4017F50:
          puVar6 = *(uint **)(_bufhash + iVar1 + 4);
          if ((uint *)(_bufhash + iVar1) != puVar6) {
            do {
              if ((((param_1 != puVar6) && (puVar6[0x10] == param_1[0x10])) &&
                  ((*puVar6 & 0x10000) == 0)) &&
                 (((puVar6[5] != 0 && ((int)puVar6[9] <= (int)((uVar2 - 1) + (int)param_2 / iVar4)))
                  && ((int)uVar2 < (int)(puVar6[9] + (int)puVar6[5] / iVar4))))) {
                if ((*puVar6 & 8) != 0) {
                  *puVar6 = *puVar6 | 0x40;
                  _sleep(puVar6,0x15);
                  goto loc_4017F50;
                }
                *(uint *)(puVar6[4] + 0xc) = puVar6[3];
                *(uint *)(puVar6[3] + 0x10) = puVar6[4];
                *puVar6 = *puVar6 | 8;
                if ((*puVar6 & 0x200) != 0) goto loc_4017EF2;
                *puVar6 = *puVar6 | 0x10000;
                _brelse(puVar6);
              }
              puVar6 = (uint *)puVar6[1];
              if ((uint *)(_bufhash + iVar1) == puVar6) break;
            } while( true );
          }
        }
      }
      uVar3 = _allocbuf(param_1,param_2);
    }
    else {
      _bwrite(param_1);
      uVar3 = 0;
    }
  }
  return uVar3;
loc_4017EF2:
  _bwrite(puVar6);
  goto loc_4017F50;
}
