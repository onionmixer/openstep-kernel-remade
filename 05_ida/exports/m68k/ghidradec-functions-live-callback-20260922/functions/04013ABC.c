
undefined4 _sogetopt(sword *param_1,int param_2,uint param_3,int *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 6) == 0) {
      return 0x2a;
    }
    pcVar1 = *(code **)(*(int *)(param_1 + 6) + 0x16);
    if (pcVar1 == (code *)0x0) {
      return 0x2a;
    }
    uVar2 = (*pcVar1)(0,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  iVar3 = _m_get(1,10);
  *(undefined2 *)(iVar3 + 8) = 4;
  if (param_3 != 0x100) {
    if (0x100 < (int)param_3) {
      if (param_3 != 0x1004) {
        if (0x1004 < (int)param_3) {
          if (param_3 == 0x1006) {
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)param_1[0x16];
          }
          else if ((int)param_3 < 0x1006) {
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)param_1[0x21];
          }
          else if (param_3 == 0x1007) {
            *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x28];
            param_1[0x28] = 0;
          }
          else {
            if (param_3 != 0x1008) goto loc_4013C64;
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)*param_1;
          }
          goto loc_4013C70;
        }
        if (param_3 == 0x1002) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x12];
          goto loc_4013C70;
        }
        if (0x1002 < (int)param_3) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x20];
          goto loc_4013C70;
        }
        if (param_3 == 0x1001) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x1d];
          goto loc_4013C70;
        }
        goto loc_4013C64;
      }
      *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x15];
      goto loc_4013C70;
    }
    if (param_3 != 0x10) {
      if ((int)param_3 < 0x11) {
        if (param_3 != 4) {
          if ((int)param_3 < 5) {
            uVar4 = 1;
          }
          else {
            uVar4 = 8;
          }
loc_4013B4C:
          if (uVar4 != param_3) {
loc_4013C64:
            _m_free(iVar3);
            return 0x2a;
          }
        }
      }
      else if (param_3 != 0x40) {
        if (0x40 < (int)param_3) {
          if (param_3 != 0x80) goto loc_4013C64;
          *(undefined2 *)(iVar3 + 8) = 8;
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = *(byte *)((int)param_1 + 3) & 0x80;
          *(int *)(iVar3 + 4 + *(int *)(iVar3 + 4)) = (int)param_1[2];
          goto loc_4013C70;
        }
        uVar4 = 0x20;
        goto loc_4013B4C;
      }
    }
  }
  *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = param_3 & (int)param_1[1];
loc_4013C70:
  *param_4 = iVar3;
  return 0;
}

