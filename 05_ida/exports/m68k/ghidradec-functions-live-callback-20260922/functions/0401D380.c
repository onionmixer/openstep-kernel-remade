
void _raw_input(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)_m_get(0,2);
  if (puVar1 == (undefined4 *)0x0) {
    _m_freem(param_1);
  }
  else {
    *puVar1 = param_1;
    *(undefined2 *)(puVar1 + 2) = 0x24;
    puVar2 = (undefined4 *)(puVar1[1] + (int)puVar1);
    puVar2[1] = *param_4;
    puVar2[2] = param_4[1];
    puVar2[3] = param_4[2];
    puVar2[4] = param_4[3];
    puVar2[5] = *param_3;
    puVar2[6] = param_3[1];
    puVar2[7] = param_3[2];
    puVar2[8] = param_3[3];
    *puVar2 = *param_2;
    if (dword_40B5A6C < dword_40B5A70) {
      puVar1[0x1f] = 0;
      puVar2 = puVar1;
      if (dword_40B5A68 != (undefined4 *)0x0) {
        dword_40B5A68[0x1f] = puVar1;
        puVar2 = _rawintrq;
      }
      _rawintrq = puVar2;
      dword_40B5A6C = dword_40B5A6C + 1;
      dword_40B5A68 = puVar1;
    }
    else {
      _m_freem(puVar1);
    }
    _netisr = _netisr | 1;
    _wakeup(&_soft_net_wakeup);
  }
  return;
}

