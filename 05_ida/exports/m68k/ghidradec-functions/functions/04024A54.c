
void _tcp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  pcVar1 = _tcp_notify;
  if (param_1 == 4) {
    pcVar1 = _tcp_quench;
  }
  else {
    if (0x15 < param_1) {
      return;
    }
    if (_inetctlerrmap[param_1] == '\0') {
      return;
    }
  }
  if (param_3 == (byte *)0x0) {
    uVar4 = 0;
    uVar2 = 0;
    uVar3 = _zeroin_addr;
  }
  else {
    uVar4 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4);
    uVar2 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4 + 2);
    uVar3 = *(undefined4 *)(param_3 + 0xc);
  }
  _in_pcbnotify(&_tcb,param_2,uVar2,uVar3,uVar4,param_1,pcVar1);
  return;
}
