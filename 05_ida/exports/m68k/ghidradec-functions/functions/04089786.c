
undefined4 _vidopen(void)

{
  int iVar1;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    return 0x13;
  }
  return 0;
}
