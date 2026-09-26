
void _tcp_notify(int param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(*(int *)(param_1 + 0x18) + 0x50);
  if ((*(sword *)(*(int *)(param_1 + 0x18) + 6) == 4) ||
     (((sVar1 != 0x41 && (sVar1 != 0x33)) && (sVar1 != 0x40)))) {
    *(sword *)(*(int *)(param_1 + 0x1c) + 0x6a) = sVar1;
    _wakeup(*(int *)(param_1 + 0x18) + 0x4e);
    _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x22);
    _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x38);
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x18) + 0x50) = 0;
  }
  return;
}

