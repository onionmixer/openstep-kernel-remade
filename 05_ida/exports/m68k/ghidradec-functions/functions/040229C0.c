
undefined4 _rip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 != 0) {
      if (param_1 != 1) {
        return 0;
      }
      if (param_4 == 1) {
        uVar3 = _ip_pcbopts(iVar1 + 0x34,*param_5);
        return uVar3;
      }
      if (((param_4 < 1) || (7 < param_4)) || (param_4 < 3)) {
        uVar3 = _ip_mrouter_cmd(param_4,param_2,*param_5);
      }
      else {
        uVar3 = _ip_setmoptions(param_4,iVar1 + 0x4e,*param_5);
      }
      goto loc_4022ABE;
    }
    if (param_4 == 1) {
      iVar2 = _m_get(1,10);
      *param_5 = iVar2;
      if (*(int *)(iVar1 + 0x34) == 0) {
        *(undefined2 *)(iVar2 + 8) = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + 4);
        *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar1 + 0x34) + 8);
        iVar2 = *param_5;
        _bcopy(*(int *)(*(int *)(iVar1 + 0x34) + 4) + *(int *)(iVar1 + 0x34),
               *(int *)(iVar2 + 4) + iVar2,(int)*(sword *)(iVar2 + 8));
      }
      goto loc_4022ABE;
    }
    if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
      uVar3 = _ip_getmoptions(param_4,*(undefined4 *)(iVar1 + 0x4e),param_5);
      goto loc_4022ABE;
    }
  }
  uVar3 = 0x16;
loc_4022ABE:
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free(*param_5);
  }
  return uVar3;
}
