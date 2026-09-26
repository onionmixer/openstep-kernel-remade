
uint _dspq_awaited_conditions(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((undefined4 **)dword_40C6E46 != &dword_40C6E46) {
    switch(*dword_40C6E46) {
    case :
      uVar2 = dword_40C6E46[1];
      if ((uVar2 & 0x1800) != 0) {
        uVar1 = 8;
      }
      if ((uVar2 & 0x600) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((uVar2 & 0x100) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((uVar2 & 0x800000) == 0) goto loc_4083DDE;
    case :
      uVar2 = 1;
      break;
    case :
    case :
    case :
    case :
      uVar2 = 4;
      break;
    :
      goto loc_4083DDE;
    case :
    case :
    case :
    case :
      uVar2 = 2;
    }
    uVar1 = uVar2 | uVar1;
  }
loc_4083DDE:
  if ((((uVar1 == 0) && ((dword_40C6E84 & 0x10000) != 0)) && (dword_40C6DFC != 0)) &&
     (dword_40C6DFC + 0x3e != *(int *)(dword_40C6DFC + 0x3e))) {
    uVar1 = 4;
  }
  return uVar1;
}

