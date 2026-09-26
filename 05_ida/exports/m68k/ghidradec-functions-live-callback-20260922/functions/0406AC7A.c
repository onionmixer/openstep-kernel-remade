
void _fc_eject(int *param_1)

{
  int iVar1;
  undefined auStack_5e [90];
  
  if (((byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f)) & *(byte *)(*param_1 + 2)) == 0) {
    _fc_motor_on(param_1);
  }
  iVar1 = *(int *)((int)param_1 + 0x25e);
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  _bzero(auStack_5e,0x5a);
  _fd_gen_seek(iVar1,auStack_5e,0x4f,0);
  iVar1 = _fc_send_cmd(param_1,auStack_5e);
  if (iVar1 == 0) {
    _fc_flpctl_bset(param_1,0x80);
    _delay(3);
    _fc_flpctl_bclr(param_1,0x80);
    _fc_flags_bclr(param_1,0x40);
    sub_406B38A(param_1,2000000,4000000);
    *(undefined4 *)(param_1[7] + 0x3e) = 0;
  }
  else {
    *(int *)(param_1[7] + 0x3e) = iVar1;
  }
  return;
}

