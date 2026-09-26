
undefined4 sub_408B27A(void)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  dword_40B5184 = _ev_register_screen(&iStack_8,0,&loc_408AFD0,&loc_408ACC2,&loc_408AD8A,&aHvO);
  if (dword_40B5184 < 0) {
    uVar2 = 6;
  }
  else {
    dword_40B518C = *(int *)(iStack_8 + 4);
    _bzero(dword_40B518C,*(undefined4 *)(iStack_8 + 8));
    *(undefined *)(dword_40B518C + 8) = 1;
    iVar1 = dword_40B518C;
    uVar2 = *(undefined4 *)(iStack_8 + 0x10);
    *(undefined4 *)(dword_40B518C + 0x30) = *(undefined4 *)(iStack_8 + 0xc);
    *(undefined4 *)(iVar1 + 0x34) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

