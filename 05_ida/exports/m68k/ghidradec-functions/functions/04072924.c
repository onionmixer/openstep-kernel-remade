
undefined4 _np_getgpi(undefined4 *param_1,byte *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  sword sVar6;
  int iVar7;
  byte abStack_c [4];
  int iStack_8;
  
  uVar1 = *param_1;
  bVar2 = false;
  iVar7 = 2;
  do {
    uVar5 = 5;
    while( true ) {
      do {
        _np_send(uVar1,4,0);
        iVar4 = 0;
        do {
          iVar3 = _np_recv(uVar1,&iStack_8,abStack_c);
          if ((iVar3 != 0) && (iStack_8 == 0xc4)) {
            bVar2 = true;
            goto loc_407299C;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x28);
      } while ((!bVar2) &&
              (sVar6 = (sword)uVar5 + -1, uVar5 = CONCAT22((sword)(uVar5 >> 0x10),sVar6),
              sVar6 != -1));
      if (bVar2) break;
      uVar5 = (uVar5 & 0xffff0000) - 1;
      if ((int)uVar5 < 0) {
        return 0;
      }
    }
loc_407299C:
    *param_2 = ~abStack_c[0] & 0x3f;
    if ((~abStack_c[0] & 0x10) != 0) {
      return 1;
    }
    if ((*(int *)((int)param_1 + 0x126) == 1) || (iVar7 = iVar7 + -1, iVar7 < 1)) {
      if (*(int *)((int)param_1 + 0x126) != 1) {
        if (*(int *)((int)param_1 + 0x126) == 4) {
          _np_printing_shutdown(param_1);
        }
        _np_setstate(param_1,1);
      }
      return 1;
    }
  } while( true );
}
