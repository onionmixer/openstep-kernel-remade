/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a5e4 */

undefined4 _brealloc(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  
  if (param_2 == param_1[5]) {
    uVar3 = 1;
  }
  else {
    uVar1 = *param_1;
    if ((uVar1 & 0x200) == 0) {
      if ((int)param_2 < (int)param_1[5]) {
        if ((uVar1 & 0x20000) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_brealloc_001db5de);
        }
        uVar3 = _allocbuf(param_1,param_2);
      }
      else {
        *param_1 = uVar1 & 0xfffffffd;
        uVar1 = param_1[0x10];
        if (uVar1 != 0) {
          iVar4 = (**(code **)(*(int *)(uVar1 + 0x1c) + 0x80))(uVar1);
          if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_Couldn_t_determine_device_blocks_001db5e7);
          }
          uVar1 = param_1[9];
          uVar5 = uVar1;
          if ((int)uVar1 < 0) {
            uVar5 = uVar1 + 7;
          }
          uVar5 = ((int)uVar5 >> 3) + param_1[0x10] & 0xf;
LAB_0011a726:
          puVar7 = (uint *)(&DAT_001e8884)[uVar5 * 3];
          do {
            if (puVar7 == (uint *)(&_bufhash + uVar5 * 0xc)) {
              uVar3 = _allocbuf(param_1,param_2);
              return uVar3;
            }
            if ((((puVar7 != param_1) && (puVar7[0x10] == param_1[0x10])) &&
                ((*puVar7 & 0x10000) == 0)) &&
               (((puVar7[5] != 0 && ((int)puVar7[9] <= (int)((int)param_2 / iVar4 + -1 + uVar1))) &&
                ((int)uVar1 < (int)((int)puVar7[5] / iVar4 + puVar7[9]))))) {
              uVar3 = _splhigh();
              if ((*puVar7 & 8) != 0) {
                *puVar7 = *puVar7 | 0x40;
                uVar8 = 0x15;
                _sleep((uint)puVar7);
                _splx(uVar3,puVar7,uVar8);
                goto LAB_0011a726;
              }
              _splx(uVar3);
              uVar3 = _splbio();
              *(uint *)(puVar7[4] + 0xc) = puVar7[3];
              *(uint *)(puVar7[3] + 0x10) = puVar7[4];
              *(byte *)puVar7 = (byte)*puVar7 | 8;
              _splx(uVar3);
              uVar2 = *puVar7;
              if ((uVar2 & 0x200) != 0) goto code_r0x0011a7be;
              *puVar7 = uVar2 | 0x10000;
              if ((uVar2 & 0x40) != 0) {
                _wakeup(puVar7);
              }
              if ((_bfreelist & 0x40) != 0) {
                _bfreelist = _bfreelist & 0xffffffbf;
                _wakeup(&_bfreelist);
              }
              if ((*puVar7 & 0x400200) == 0x400000) {
                *puVar7 = *puVar7 | 0x10000;
              }
              uVar2 = *puVar7;
              if ((uVar2 & 4) != 0) {
                if ((uVar2 & 0x20000) == 0) {
                  FUN_0011b26c(puVar7);
                }
                else {
                  *puVar7 = uVar2 & 0xfffffffb;
                }
              }
              uVar3 = _splhigh();
              if ((int)puVar7[6] < 1) {
                DAT_001e8838[4] = (uint)puVar7;
                puVar7[3] = (uint)DAT_001e8838;
                DAT_001e8838 = puVar7;
                puVar7[4] = (uint)&DAT_001e882c;
              }
              else {
                uVar2 = *puVar7;
                if ((uVar2 & 0x10004) == 0) {
                  if ((uVar2 & 0x20000) == 0) {
                    puVar6 = &DAT_001e87a4;
                    if ((char)uVar2 < '\0') {
                      puVar6 = (undefined4 *)&DAT_001e87e8;
                    }
                  }
                  else {
                    puVar6 = &_bfreelist;
                  }
                  *(uint **)(puVar6[4] + 0xc) = puVar7;
                  puVar7[4] = puVar6[4];
                  puVar6[4] = puVar7;
                  puVar7[3] = (uint)puVar6;
                }
                else {
                  DAT_001e87f4[4] = (uint)puVar7;
                  puVar7[3] = (uint)DAT_001e87f4;
                  DAT_001e87f4 = puVar7;
                  puVar7[4] = (uint)&DAT_001e87e8;
                }
              }
              *puVar7 = *puVar7 & 0xffbffe37;
              _splx(uVar3);
            }
            puVar7 = (uint *)puVar7[1];
          } while( true );
        }
        uVar3 = _allocbuf(param_1,param_2);
      }
    }
    else {
      *param_1 = uVar1 & 0xfffffdf8;
      if ((int)param_1[6] < (int)param_1[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bwrite_001db583);
      }
      (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
      if ((uVar1 & 0x100) == 0) {
        _biowait(param_1);
        _brelse(param_1);
      }
      else {
        *(byte *)param_1 = (byte)*param_1 | 0x80;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
code_r0x0011a7be:
  *puVar7 = uVar2 & 0xfffffdf8;
  if ((int)puVar7[6] < (int)puVar7[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  (**(code **)(*(int *)(puVar7[0x10] + 0x1c) + 0x54))(puVar7);
  if ((uVar2 & 0x100) == 0) {
    _biowait(puVar7);
    _brelse(puVar7);
  }
  else {
    *(byte *)puVar7 = (byte)*puVar7 | 0x80;
  }
  goto LAB_0011a726;
}

