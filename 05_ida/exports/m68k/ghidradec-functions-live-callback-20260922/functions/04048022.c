
undefined4 _host_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          return 4;
        }
        if (*param_4 < 5) {
          return 5;
        }
        *param_3 = dword_40C22D0;
        param_3[1] = dword_40C22D4;
        param_3[2] = dword_40C22D8;
        iVar1 = _master_processor;
        param_3[3] = (&dword_40B5DCC)[*(int *)(_master_processor + 0x13c) * 8];
        param_3[4] = (&dword_40B5DD0)[*(int *)(iVar1 + 0x13c) * 8];
        uVar2 = 5;
      }
      else if (param_2 == 3) {
        if (*param_4 < 2) {
          return 5;
        }
        iVar1 = _tick / 1000;
        *param_3 = iVar1;
        param_3[1] = iVar1;
        uVar2 = 2;
      }
      else {
        if (param_2 != 4) {
          return 4;
        }
        if (*param_4 < 6) {
          return 5;
        }
        _bcopy(_avenrun,param_3,0xc);
        _bcopy(_mach_factor,param_3 + 3,0xc);
        uVar2 = 6;
      }
      *param_4 = uVar2;
      return 0;
    }
    if (*param_4 != 0) {
      *param_4 = 0;
      iVar1 = 0;
      piVar3 = &_machine_slot;
      do {
        piVar4 = param_3;
        if ((*piVar3 != 0) && ((&dword_40B5DD4)[iVar1 * 8] != 0)) {
          piVar4 = param_3 + 1;
          *param_3 = iVar1;
          *param_4 = *param_4 + 1;
        }
        piVar3 = piVar3 + 8;
        iVar1 = iVar1 + 1;
        param_3 = piVar4;
      } while (iVar1 < 1);
      return 0;
    }
  }
  return 4;
}

