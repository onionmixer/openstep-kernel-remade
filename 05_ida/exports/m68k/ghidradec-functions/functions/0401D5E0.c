
undefined4 _raw_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = 0;
  if (param_2 == 0xb) {
loc_401D7DE:
    return 0x2d;
  }
  if ((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) {
loc_401d618:
    uVar2 = 0x2d;
    goto loc_401D7D0;
  }
  if ((iVar3 == 0) && (param_2 != 0)) goto loc_401D6DC;
  switch(param_2) {
  case :
    if (-1 < *(char *)(param_1 + 7)) {
      uVar2 = 0xd;
      break;
    }
    if (iVar3 == 0) {
      uVar2 = _raw_attach(param_1,param_4);
      break;
    }
    goto loc_401D6DC;
  case :
    if (iVar3 != 0) {
      _raw_detach(iVar3);
      break;
    }
    goto loc_401D746;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 1) == 0) {
      uVar2 = _raw_bind(param_1,param_4);
      break;
    }
loc_401D6DC:
    uVar2 = 0x16;
    break;
  case :
  case :
  case :
  case :
    goto loc_401d618;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 2) == 0) {
      _raw_connaddr(iVar3,param_4);
      _soisconnected(param_1);
      break;
    }
loc_401D72A:
    uVar2 = 0x38;
    break;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 2) != 0) {
      _raw_disconnect(iVar3);
      _soisdisconnected(param_1);
      break;
    }
    goto loc_401D746;
  case :
    _socantsendmore(param_1);
    break;
  case :
  case :
    goto loc_401D7DE;
  case :
    if (param_4 != 0) {
      if ((*(byte *)(iVar3 + 0x4d) & 2) == 0) {
        _raw_connaddr(iVar3,param_4);
loc_401D74C:
        uVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0xe))(param_3,param_1);
        param_3 = 0;
        if (param_4 != 0) {
          *(word *)(iVar3 + 0x4c) = *(word *)(iVar3 + 0x4c) & 0xfffd;
        }
        break;
      }
      goto loc_401D72A;
    }
    if ((*(byte *)(iVar3 + 0x4d) & 2) != 0) goto loc_401D74C;
loc_401D746:
    uVar2 = 0x39;
    break;
  case :
    _raw_disconnect(iVar3);
    _sofree(param_1);
    _soisdisconnected(param_1);
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aRawUsrreq);
  case :
    return 0;
  case :
    iVar1 = *(int *)(param_4 + 4);
    iVar3 = iVar3 + 0x1c;
    goto loc_401D7B0;
  case :
    iVar1 = *(int *)(param_4 + 4);
    iVar3 = iVar3 + 0xc;
loc_401D7B0:
    _bcopy(iVar3,iVar1 + param_4,0x10);
    *(undefined2 *)(param_4 + 8) = 0x10;
  }
loc_401D7D0:
  if (param_3 != 0) {
    _m_freem(param_3);
  }
  return uVar2;
}
