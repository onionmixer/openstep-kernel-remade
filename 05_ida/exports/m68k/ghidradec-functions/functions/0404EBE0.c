
void _power_init(void)

{
  int iVar1;
  
  if (dword_40AF944 == 0) {
    iVar1 = _PMConnect();
    if (iVar1 == 0) {
      _power_callout(0,0);
    }
    dword_40B39C2 = 0;
    dword_40AF944 = 1;
  }
  return;
}
