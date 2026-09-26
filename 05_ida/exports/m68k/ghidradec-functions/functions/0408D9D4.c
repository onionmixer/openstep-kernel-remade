
undefined4 sub_408D9D4(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _m_clalloc(1,2,0);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    uVar1 = _page_size + iVar2;
    uVar4 = iVar2 + 0xf;
    if ((int)uVar4 < 0) {
      uVar4 = iVar2 + 0x1e;
    }
    while (uVar5 = uVar4 & 0xfffffff0, uVar5 + 0x62e <= uVar1) {
      sub_408D9AA(uVar5);
      dword_40B244E = dword_40B244E + 1;
      uVar4 = uVar5 + 0x63d;
      if ((int)uVar4 < 0) {
        uVar4 = uVar5 + 0x64c;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}
