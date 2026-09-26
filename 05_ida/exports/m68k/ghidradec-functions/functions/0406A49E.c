
int _ev_register_screen(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (_evg == 0) {
    iVar2 = -1;
  }
  else {
    if (_screens == 0) {
      dword_40B1278 = _evs;
    }
    puVar1 = (undefined4 *)(_evScreen + _screens * 0x28);
    *param_1 = (int)puVar1;
    *puVar1 = param_2;
    puVar1[7] = param_3;
    puVar1[6] = param_4;
    puVar1[8] = param_5;
    puVar1[9] = param_6;
    if (puVar1[2] != 0) {
      puVar1[1] = dword_40B1278;
    }
    dword_40B1278 = puVar1[2] + dword_40B1278;
    iVar2 = _screens + 0x100;
    _screens = _screens + 1;
  }
  return iVar2;
}
