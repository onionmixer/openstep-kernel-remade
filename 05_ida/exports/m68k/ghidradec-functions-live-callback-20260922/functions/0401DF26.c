
undefined4
_arpresolve(uint param_1,undefined *param_2,uint param_3,uint param_4,uint *param_5,
           undefined *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined uStack_15;
  undefined2 auStack_14 [2];
  uint uStack_10;
  
  *param_7 = 0;
  if ((*param_5 & 0xf0000000) == 0xe0000000) {
    *param_6 = 1;
    param_6[1] = 0;
    param_6[2] = 0x5e;
    param_6[3] = *(byte *)((int)param_5 + 1) & 0x7f;
    param_6[4] = *(undefined *)((int)param_5 + 2);
    param_6[5] = (char)*param_5;
    return 1;
  }
  iVar1 = _in_broadcast(*param_5);
  if (iVar1 == 0) {
    iVar1 = _in_lnaof(*param_5);
    if (param_3 == *param_5) {
      if (_useloopback == 0) {
        uVar5 = 4;
        goto loc_401DFFE;
      }
      auStack_14[0] = 2;
      uStack_10 = *param_5;
      _looutput(_loifp,param_4,auStack_14);
    }
    else {
      puVar4 = (uint *)(_arptab + (*param_5 % 0x13) * 0xb4);
      iVar3 = 0;
      do {
        if ((*param_5 == *puVar4) && ((param_1 == 0 || (param_1 == puVar4[4])))) break;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 5;
      } while (iVar3 < 9);
      if (8 < iVar3) {
        puVar4 = (uint *)0x0;
      }
      if (puVar4 == (uint *)0x0) {
        if (*(char *)(param_1 + 0xd) < '\0') {
          _bcopy(param_2,param_6,3);
          param_6[3] = (byte)((uint)(iVar1 << 9) >> 0x19);
          param_6[4] = (char)((uint)iVar1 >> 8);
          uStack_15 = (undefined)iVar1;
          param_6[5] = uStack_15;
          return 1;
        }
        iVar1 = _arptnew(param_1,param_5);
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aArpresolveNoFr);
        }
        *(uint *)(iVar1 + 0xc) = param_4;
        _arpwhohas(param_1,param_2,param_3,param_5);
      }
      else {
        *(undefined *)((int)puVar4 + 10) = 0;
        if ((*(byte *)((int)puVar4 + 0xb) & 2) != 0) {
          _bcopy(puVar4 + 1,param_6,6);
          if ((*(byte *)((int)puVar4 + 0xb) & 0x10) != 0) {
            *param_7 = 1;
          }
          return 1;
        }
        if (puVar4[3] != 0) {
          _m_freem(puVar4[3]);
        }
        puVar4[3] = param_4;
        _arpwhohas(param_1,param_2,param_3,param_5);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar5 = (uint)word_40AE906._0_1_;
    param_2 = DAT_40ae90a + uVar5 + (byte)word_40AE906;
loc_401DFFE:
    _bcopy(param_2,param_6,uVar5);
    uVar2 = 1;
  }
  return uVar2;
}

