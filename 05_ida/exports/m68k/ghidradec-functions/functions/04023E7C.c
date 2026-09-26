
void _tcp_xmit_timer(int param_1)

{
  sword sVar1;
  sword sVar2;
  
  dword_40BBD48 = dword_40BBD48 + 1;
  sVar1 = *(sword *)(param_1 + 0x60);
  if (sVar1 == 0) {
    *(sword *)(param_1 + 0x60) = *(sword *)(param_1 + 0x5a) << 3;
    *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x5a) << 1;
  }
  else {
    sVar2 = *(sword *)(param_1 + 0x5a) - ((sVar1 >> 3) + 1);
    *(sword *)(param_1 + 0x60) = sVar2 + sVar1;
    if ((sword)(sVar2 + sVar1) < 1) {
      *(undefined2 *)(param_1 + 0x60) = 1;
    }
    if (sVar2 < 0) {
      sVar2 = -sVar2;
    }
    sVar1 = (sVar2 - (*(sword *)(param_1 + 0x62) >> 2)) + *(sword *)(param_1 + 0x62);
    *(sword *)(param_1 + 0x62) = sVar1;
    if (sVar1 < 1) {
      *(undefined2 *)(param_1 + 0x62) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x5a) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  sVar1 = *(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 3);
  *(sword *)(param_1 + 0x14) = sVar1;
  if ((int)sVar1 < (int)(uint)*(word *)(param_1 + 100)) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
  }
  else if (0x80 < sVar1) {
    *(undefined2 *)(param_1 + 0x14) = 0x80;
  }
  *(undefined2 *)(param_1 + 0x6a) = 0;
  return;
}
