
/* WARNING: Type propagation algorithm not settling */

int _unp_bind(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int aiStack_42 [2];
  undefined2 uStack_3a;
  
  iVar2 = *(int *)(param_2 + 4) + param_2;
  if ((param_1[1] == 0) && (*(sword *)(param_2 + 8) != 0x70)) {
    *(undefined *)(iVar2 + *(sword *)(param_2 + 8)) = 0;
    _vattr_null(aiStack_42 + 1);
    aiStack_42[1] = 6;
    uStack_3a = 0x1ff;
    iVar2 = _vn_create(iVar2 + 2,1,aiStack_42 + 1,1,0,aiStack_42);
    if (iVar2 == 0) {
      *(undefined4 *)(aiStack_42[0] + 0x20) = *param_1;
      param_1[1] = aiStack_42[0];
      uVar1 = _m_copy(param_2,0,1000000000);
      param_1[6] = uVar1;
      iVar2 = 0;
    }
    else if (iVar2 == 0x11) {
      iVar2 = 0x30;
    }
  }
  else {
    iVar2 = 0x16;
  }
  return iVar2;
}

