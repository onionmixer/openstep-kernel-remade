
void _in_arpinput(uint param_1,uint *param_2,uint param_3,int param_4)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined2 uStack_40;
  undefined auStack_3e [14];
  undefined2 auStack_30 [2];
  uint uStack_2c;
  undefined auStack_20 [2];
  sword sStack_1e;
  sword sStack_1c;
  sword sStack_1a;
  undefined auStack_18 [20];
  
  iStack_4c = 0;
  _bcopy(*(int *)(param_4 + 4) + param_4,auStack_20,0x1c);
  sVar2 = sStack_1a;
  sVar1 = sStack_1e;
  uStack_40 = 0x806;
  if (word_40AE906 != sStack_1c) goto loc_401E6B6;
  _bcopy(auStack_18 + word_40AE906._0_1_,&uStack_44,4);
  _bcopy(auStack_20 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,&uStack_48,4);
  iVar3 = _bcmp(auStack_18,param_2,word_40AE906._0_1_);
  if (iVar3 == 0) goto loc_401E6B6;
  iVar3 = _bcmp(auStack_18,&_etherbroadcastaddr,6);
  if (iVar3 == 0) {
    _log(3,aArpEtherAddres,uStack_44);
    goto loc_401E6B6;
  }
  if (uStack_44 == param_3) {
    uVar4 = _ether_sprintf(auStack_18);
    _log(3,&aSS,aDuplicateIpAdd,uVar4);
    uStack_48 = param_3;
    if (sStack_1a != 1) goto loc_401E6B6;
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = (uint *)(_arptab + (uStack_44 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((uStack_44 == *puVar5) && ((param_1 == 0 || (param_1 == puVar5[4])))) break;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      puVar5 = (uint *)0x0;
    }
    if (puVar5 == (uint *)0x0) {
      if (param_3 == uStack_48) {
        puVar5 = (uint *)_arptnew(param_1,&uStack_44);
        _bcopy(auStack_18,puVar5 + 1,word_40AE906._0_1_);
        if (word_40AE906._0_1_ < 6) {
          _bzero((int)puVar5 + word_40AE906._0_1_ + 4,6 - (uint)word_40AE906._0_1_);
        }
        *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      }
    }
    else {
      _bcopy(auStack_18,puVar5 + 1,word_40AE906._0_1_);
      if (word_40AE906._0_1_ < 6) {
        _bzero((int)puVar5 + word_40AE906._0_1_ + 4,6 - (uint)word_40AE906._0_1_);
      }
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      if (puVar5[3] != 0) {
        auStack_30[0] = 2;
        uStack_2c = uStack_44;
        _if_output_mbuf(param_1,puVar5[3],auStack_30);
        puVar5[3] = 0;
      }
    }
  }
  if (sVar1 == 0x800) {
    if (sStack_1a != 1) goto loc_401E48C;
  }
  else if (sVar1 == 0x1000) {
    if (puVar5 != (uint *)0x0) {
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 0x10;
    }
    if (sStack_1a != 1) goto loc_401E6B6;
loc_401E48C:
    if ((*(byte *)(param_1 + 0xd) & 0x20) != 0) goto loc_401E6B6;
  }
  if (uStack_48 == param_3) {
    _bcopy(auStack_18,auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,
           (uint)word_40AE906._0_1_);
  }
  else {
    param_2 = (uint *)(_arptab + (uStack_48 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((uStack_48 == *param_2) && ((param_1 == 0 || (param_1 == param_2[4])))) break;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      param_2 = (uint *)0x0;
    }
    if ((param_2 == (uint *)0x0) || ((*(byte *)((int)param_2 + 0xb) & 8) == 0)) {
loc_401E6B6:
      _m_freem(param_4);
      return;
    }
    _bcopy(auStack_18,auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,
           (uint)word_40AE906._0_1_);
    param_2 = param_2 + 1;
  }
  _bcopy(param_2,auStack_18,word_40AE906._0_1_);
  _bcopy(auStack_18 + word_40AE906._0_1_,
         auStack_20 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,(uint)(byte)word_40AE906
        );
  _bcopy(&uStack_48,auStack_18 + word_40AE906._0_1_,(byte)word_40AE906);
  sStack_1a = 2;
  _bcopy(auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,auStack_3e,
         (uint)word_40AE906._0_1_);
  _bcopy(&uStack_40,auStack_3e + (uint)word_40AE906._0_1_ * 2,2);
  if (sVar2 == 2) {
    sStack_1e = 0x1000;
  }
  else if ((sVar1 == 0x800) && ((*(byte *)(param_1 + 0xd) & 0x20) == 0)) {
    iStack_4c = _m_copy(param_4,0,1000000000);
  }
  _bcopy(auStack_20,*(int *)(param_4 + 4) + param_4,0x1c);
  uStack_40 = 0;
  _if_output_mbuf(param_1,param_4,&uStack_40);
  if (iStack_4c == 0) {
    return;
  }
  sStack_1e = 0x1000;
  _bcopy(auStack_20,*(int *)(iStack_4c + 4) + iStack_4c,0x1c);
  _if_output_mbuf(param_1,iStack_4c,&uStack_40);
  return;
}
