
void _in_bootp_timeout(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = 0;
  _sbwakeup(iVar1 + 0x22);
  return;
}
