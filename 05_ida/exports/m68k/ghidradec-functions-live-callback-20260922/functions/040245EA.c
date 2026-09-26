
void _tcp_setpersist(int param_1)

{
  sword sVar1;
  
  if (*(sword *)(param_1 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTcpOutputRexmt);
  }
  sVar1 = (sword)*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4) *
          (sword)((int)*(sword *)(param_1 + 0x62) +
                  ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x12) >> 1);
  *(sword *)(param_1 + 0xc) = sVar1;
  if (sVar1 < 10) {
    *(undefined2 *)(param_1 + 0xc) = 10;
  }
  else if (0x78 < sVar1) {
    *(undefined2 *)(param_1 + 0xc) = 0x78;
  }
  if (*(sword *)(param_1 + 0x12) < 0xc) {
    *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
  }
  return;
}

