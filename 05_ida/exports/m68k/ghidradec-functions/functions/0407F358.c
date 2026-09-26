
void sub_407F358(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc2;
  _bzero(_sd_sdd + iVar1,0xc2);
  *(undefined **)(_sd_sdd + iVar1 + 8) = _sd_sd + param_1 * 0x50;
  *(uint *)(_sd_sdd + iVar1 + 0xb2) = iVar1 + 0x40c5ee7U & 0xfffffff0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xc) = 0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0x1c) = 0;
  _sd_sdd[iVar1 + 0x10] = 0;
  _sd_sdd[iVar1 + 0x15] = 10;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xbe) = 0xffffffff;
  return;
}
