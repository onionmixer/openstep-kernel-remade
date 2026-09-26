
void _fc_cmd_xfr(int *param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *param_1;
  pbVar2 = (byte *)param_1[7];
  bVar3 = pbVar2[10];
  uVar4 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if ((((uVar4 ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  *(undefined4 *)(param_2 + 0x1c) = *_event_high;
  *(uint *)(param_2 + 0x18) = *_event_middle | uVar4;
  switch(bVar3 & 0x1f) {
  case :
  case :
  case :
  case :
  case :
  case :
    break;
  :
    pbVar2[0xb] = *(byte *)(param_1[7] + 0x58) | pbVar2[0xb];
  }
  if (((uint)*pbVar2 == *(uint *)((int)param_1 + 0x25e)) ||
     ((iVar5 = _fc_configure(param_1,(uint)*pbVar2), iVar5 == 0 &&
      (iVar5 = _fc_specify(param_1,*pbVar2,_fd_drive_info + *(int *)(param_2 + 0x24) * 0x44),
      iVar5 == 0)))) {
    if (((byte)(0x10 << (pbVar2[0x58] & 0x3f)) & *(byte *)(iVar1 + 2)) == 0) {
      switch(bVar3 & 0x1f) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
        _fc_motor_on(param_1);
      }
    }
    iVar5 = _fc_send_cmd(param_1,pbVar2);
  }
  *(int *)(pbVar2 + 0x3e) = iVar5;
  return;
}

