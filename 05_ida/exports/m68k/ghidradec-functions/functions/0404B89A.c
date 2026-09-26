
int _getfakefvmseg(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _getsegbyname(&aUser);
  iVar2 = sub_404B864(0x4000000);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      _fvm_seg = DAT_40af82c;
      dword_40AF844 = *(undefined4 *)(iVar2 + 0xc);
      dword_40AF848 = sub_404B924(dword_40AF844);
      iVar1 = _strcpy(unk_40AF864,*(undefined4 *)(iVar2 + 8));
      dword_40AF884 = dword_40AF844;
      dword_40AF888 = dword_40AF848;
    }
  }
  return iVar1;
}
