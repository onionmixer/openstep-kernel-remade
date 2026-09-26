
int _findexivp(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  word *pwStack_8;
  
  *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
  iVar3 = param_3;
  if (param_2 != 0) {
    *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  }
  do {
    iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 100))(iVar3,&pwStack_8);
    if (iVar1 != 0) {
loc_4026C22:
      _vn_rele(iVar3);
      if (param_2 != 0) {
        _vn_rele(param_2);
      }
      return iVar1;
    }
    iVar2 = _findexport(*(int *)(iVar3 + 0x24) + 0x14,pwStack_8);
    *param_1 = iVar2;
    _kfree(pwStack_8,*pwStack_8 + 2);
    if (*param_1 != 0) goto loc_4026C22;
    if ((*(byte *)(iVar3 + 5) & 1) != 0) {
      iVar1 = 0x16;
      goto loc_4026C22;
    }
    if (param_2 == 0) {
      iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x20))
                        (iVar3,&asc_40A6712,&param_2,*(undefined4 *)(_active_u + 0x1a),0,0);
      if (iVar1 != 0) goto loc_4026C22;
    }
    _vn_rele(iVar3);
    iVar3 = param_2;
    param_2 = 0;
  } while( true );
}
