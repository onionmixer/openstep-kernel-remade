
void _vidInterruptEnable(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    return;
  }
  dword_40B2286 = param_1;
  dword_40B5188 = param_2;
  (*(&off_40B22AC)[dword_40B2282 * 0xb])();
  return;
}
