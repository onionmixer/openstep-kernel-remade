
void _km_clear_eol(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  _km_begin_access();
  iVar3 = (int)word_40B68E0;
  if (param_1 == 0) {
    iVar3 = iVar3 - word_40B68D8;
  }
  iVar4 = 0;
  do {
    iVar1 = (int)word_40B68DE;
    if (param_1 == 0) {
      iVar1 = word_40B68D8 + iVar1;
    }
    puVar2 = (undefined4 *)
             ((uint)(iVar1 << 5) / _km_coni +
             dword_40B6940 * (iVar4 + ((int)word_40B68DA + (int)word_40B68DC) * 0xc) + dword_40B6980
             );
    if (_km_coni == 0x10) {
      iVar1 = 0;
      if (0 < iVar3) {
        do {
          *(undefined2 *)puVar2 = dword_40B68F4._2_2_;
          iVar1 = iVar1 + 1;
          puVar2 = (undefined4 *)((int)puVar2 + 2);
        } while (iVar1 < iVar3);
      }
    }
    else {
      iVar1 = 0;
      if (0 < (iVar3 << 3) / (int)_km_coni) {
        do {
          *puVar2 = dword_40B68F4;
          iVar1 = iVar1 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar1 < (iVar3 << 3) / (int)_km_coni);
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  _km_end_access();
  return;
}

