
void _donice(int param_1,int param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 2);
  if ((((sVar1 == 0) || (sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 6), sVar2 == 0)) ||
      (*(sword *)(param_1 + 0x2c) == sVar1)) || (*(sword *)(param_1 + 0x2c) == sVar2)) {
    if (0x14 < param_2) {
      param_2 = 0x14;
    }
    if (param_2 < -0x14) {
      param_2 = -0x14;
    }
    if ((param_2 < *(char *)(param_1 + 0x15)) && (iVar4 = _suser(), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 0xd;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x66);
      iVar6 = param_2;
      if (param_2 < 0) {
        iVar6 = param_2 + 1;
      }
      iVar3 = (*(int *)(iVar4 + 0x40) + (int)(*(char *)(param_1 + 0x15) / '\x02')) - (iVar6 >> 1);
      *(char *)(param_1 + 0x15) = (char)param_2;
      _task_priority(iVar4,iVar3,0);
      for (iVar6 = *(int *)(iVar4 + 0x18); iVar6 != iVar4 + 0x18; iVar6 = *(int *)(iVar6 + 0x10)) {
        if (*(int *)(iVar6 + 0x50) < iVar3) {
          _thread_max_priority(iVar6,*(undefined4 *)(iVar6 + 0x178),iVar3);
        }
        iVar5 = _thread_priority(iVar6,iVar3,1);
        if (iVar5 != 0) goto loc_4008130;
      }
    }
  }
  else {
loc_4008130:
    *(undefined *)(dword_40B57D4 + 100) = 1;
  }
  return;
}
