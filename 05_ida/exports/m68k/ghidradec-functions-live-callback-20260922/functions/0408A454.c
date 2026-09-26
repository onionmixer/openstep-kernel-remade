
void sub_408A454(void)

{
  int iVar1;
  
  iVar1 = _mon_global;
  if (byte_40B228B != '\0') {
    byte_40B228B = '\0';
    *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) | 8;
    if (((((unk_40B6904 & 8) == 0) && (_console_o == 0)) && (0x17 < *(sword *)(iVar1 + 0x30c))) &&
       (iVar1 = *(int *)(iVar1 + 0x30e), iVar1 != 0)) {
      _callout_dispatch(2,iVar1,0);
    }
  }
  return;
}

