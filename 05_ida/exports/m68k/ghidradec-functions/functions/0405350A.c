
undefined4 _thread_info(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
loc_40536C6:
    uVar2 = 4;
  }
  else {
    if (param_2 == 1) {
      if (*param_4 < 0xb) goto loc_40536C6;
      if (((*(byte *)(param_1 + 0x4b) & 4) == 0) && (*(int *)(param_1 + 0x6c) != _sched_tick)) {
        _update_priority(param_1);
      }
      _thread_read_times(param_1,param_3,param_3 + 2);
      param_3[5] = *(undefined4 *)(param_1 + 0x4c);
      param_3[6] = *(undefined4 *)(param_1 + 0x54);
      uVar3 = ((*(uint *)(param_1 + 100) / 1000) * 3) / 5;
      param_3[4] = uVar3;
      param_3[4] = (int)(uVar3 * 1000000) / _sched_usec;
      if ((*(uint *)(param_1 + 0x48) & 0x100) == 0) {
        uVar2 = 0;
        if ((char)*(uint *)(param_1 + 0x48) < '\0') {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
      uVar3 = *(uint *)(param_1 + 0x48);
      if ((uVar3 & 0x10) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 2) == 0) {
              iVar1 = 0;
              if ((uVar3 & 1) != 0) {
                iVar1 = 3;
              }
            }
            else {
              iVar1 = 2;
            }
          }
          else {
            iVar1 = 4;
          }
        }
        else {
          iVar1 = 1;
        }
      }
      else {
        iVar1 = 5;
      }
      param_3[7] = iVar1;
      param_3[8] = uVar2;
      param_3[9] = *(undefined4 *)(param_1 + 0x88);
      if (iVar1 == 1) {
        param_3[10] = 0;
      }
      else {
        param_3[10] = _sched_tick - *(int *)(param_1 + 0x6c);
      }
      uVar3 = 0xb;
    }
    else {
      if ((param_2 != 2) || (*param_4 < 7)) goto loc_40536C6;
      *param_3 = *(undefined4 *)(param_1 + 0x5c);
      if ((*(int *)(param_1 + 0x5c) == 2) || (*(int *)(param_1 + 0x5c) == 4)) {
        param_3[1] = (_tick * *(int *)(param_1 + 0x58)) / 1000;
      }
      else {
        param_3[1] = 0;
      }
      param_3[2] = *(undefined4 *)(param_1 + 0x4c);
      param_3[3] = *(undefined4 *)(param_1 + 0x50);
      param_3[4] = *(undefined4 *)(param_1 + 0x54);
      param_3[5] = (uint)CARRY4(~*(uint *)(param_1 + 0x60),~*(uint *)(param_1 + 0x60));
      param_3[6] = *(undefined4 *)(param_1 + 0x60);
      uVar3 = 7;
    }
    *param_4 = uVar3;
    uVar2 = 0;
  }
  return uVar2;
}
