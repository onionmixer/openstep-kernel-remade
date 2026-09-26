
void sub_404E0D2(undefined *param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  param_2 = param_2 + -1;
  puVar2 = param_1;
loc_404E0EC:
  do {
    iVar1 = _miniMonGetchar();
    if (iVar1 == 10) {
loc_404E11A:
      *puVar2 = 0;
      return;
    }
    if (10 < iVar1) {
      if (iVar1 == 0xd) {
        _miniMonPutchar(10);
        goto loc_404E11A;
      }
      if (iVar1 == 0x15) {
        _miniMonPutchar(10);
        puVar2 = param_1;
      }
      else {
loc_404E148:
        if (param_2 == 0) {
          _miniMonPutchar(8);
          _miniMonPutchar(0x20);
          _miniMonPutchar(8);
        }
        else {
          *puVar2 = (char)iVar1;
          param_2 = param_2 + -1;
          puVar2 = puVar2 + 1;
        }
      }
      goto loc_404E0EC;
    }
    if (iVar1 != 8) goto loc_404E148;
    _miniMonPutchar(0x20);
    if (param_1 != puVar2) {
      _miniMonPutchar(8);
      param_2 = param_2 + 1;
      puVar2 = puVar2 + -1;
    }
  } while( true );
}
