
void sub_405C390(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _machine_exception(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    switch(param_1) {
    case :
      if (param_2 == 1) {
        uVar2 = 0xb;
      }
      else {
        uVar2 = 10;
      }
      break;
    case :
      uVar2 = 4;
      break;
    case :
      uVar2 = 8;
      break;
    case :
      uVar2 = 7;
      break;
    case :
      if (param_2 == 0x10001) {
        uVar2 = 0xd;
      }
      else if (param_2 < 0x10002) {
        if (param_2 != 0x10000) {
          return;
        }
        uVar2 = 0xc;
      }
      else {
        if (param_2 != 0x10002) {
          return;
        }
        uVar2 = 6;
      }
      break;
    case :
      uVar2 = 5;
      break;
    :
      goto loc_405C432;
    }
    *param_4 = uVar2;
  }
loc_405C432:
  return;
}

