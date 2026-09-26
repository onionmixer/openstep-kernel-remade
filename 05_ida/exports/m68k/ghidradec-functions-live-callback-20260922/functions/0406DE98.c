
int _fd_live_rw(int param_1,int param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)_kalloc(0x44);
  if (piVar2 == (int *)0x0) {
    return 0xc;
  }
  _bzero(piVar2,0x44);
  piVar2[9] = param_2;
  piVar2[8] = param_4;
  piVar2[5] = *(int *)(param_1 + 0x186) * param_3;
  *piVar2 = -(int)-(param_5 != 0);
  *(word *)((int)piVar2 + 0x1e) =
       (sword)*(undefined4 *)(param_1 + 0x10) << 3 | (sword)_fd_raw_major << 8 | 1;
  iVar3 = _fdstrategy(piVar2);
  if ((iVar3 == 0) && (_fd_polling_mode == 0)) {
    _biowait(piVar2);
  }
  if (*(uint *)(param_1 + 0x186) != 0) {
    *param_6 = (uint)piVar2[10] / *(uint *)(param_1 + 0x186);
  }
  if ((*piVar2 & 4) != 0) {
    sVar1 = *(sword *)(piVar2 + 7);
    if (sVar1 == 6) {
      iVar3 = 0x14;
    }
    else {
      if (sVar1 < 7) {
        if (sVar1 == 5) {
          iVar3 = 8;
          goto loc_406DF78;
        }
      }
      else {
        if (sVar1 == 0x16) {
          iVar3 = 4;
          goto loc_406DF78;
        }
        if (sVar1 == 0x1e) {
          iVar3 = 0xd;
          goto loc_406DF78;
        }
      }
      iVar3 = 0xb;
    }
  }
loc_406DF78:
  _kfree(piVar2,0x44);
  return iVar3;
}

