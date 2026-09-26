
undefined4 _ip_pcbopts(int *param_1,int param_2)

{
  sword sVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  if (*param_1 != 0) {
    _m_free(*param_1);
  }
  *param_1 = 0;
  if (param_2 != 0) {
    sVar1 = *(sword *)(param_2 + 8);
    if (sVar1 == 0) {
      _m_free(param_2);
    }
    else {
      uVar3 = (uint)sVar1;
      if (((uVar3 & 3) != 0) || (0x7c < uVar3 + *(int *)(param_2 + 4) + 4)) {
loc_402237E:
        _m_free(param_2);
        return 0x16;
      }
      *(sword *)(param_2 + 8) = sVar1 + 4;
      iVar5 = *(int *)(param_2 + 4) + param_2;
      pcVar6 = (char *)(iVar5 + 4);
      _ovbcopy(iVar5,pcVar6,uVar3);
      _bzero(*(int *)(param_2 + 4) + param_2,4);
      for (; (0 < (int)uVar3 && (cVar2 = *pcVar6, cVar2 != '\0')); pcVar6 = pcVar6 + uVar4) {
        if (cVar2 == '\x01') {
          uVar4 = 1;
        }
        else {
          uVar4 = (uint)(byte)pcVar6[1];
          if ((uVar4 < 2) || ((int)uVar3 < (int)uVar4)) goto loc_402237E;
        }
        if ((cVar2 == -0x7d) || (uVar7 = uVar3, cVar2 == -0x77)) {
          if (uVar4 < 7) goto loc_402237E;
          *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + -4;
          uVar7 = uVar3 - 4;
          uVar4 = uVar4 - 4;
          pcVar6[1] = (char)uVar4;
          _bcopy(pcVar6 + 3,*(int *)(param_2 + 4) + param_2,4);
          _ovbcopy(pcVar6 + 7,pcVar6 + 3,uVar3);
        }
        uVar3 = uVar7 - uVar4;
      }
      *param_1 = param_2;
    }
  }
  return 0;
}
