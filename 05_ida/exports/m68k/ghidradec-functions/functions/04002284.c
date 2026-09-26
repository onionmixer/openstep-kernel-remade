
void _rpause(void)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if ((*piVar1 != 0x1c) || (piVar1[1] != 0x7fffffff)) goto loc_40022E4;
  bVar3 = *(byte *)(_active_u + 0x254);
  iVar2 = piVar1[2];
  if (iVar2 == 1) {
    *(byte *)(_active_u + 0x254) = bVar3 & 0xf7;
loc_40022F2:
    if ((bVar3 & 8) == 0) {
      *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(dword_40B57D4 + 0x5c) = 0x7fffffff;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) goto loc_40022F2;
    }
    else if (iVar2 == 2) {
      *(byte *)(_active_u + 0x254) = bVar3 | 8;
      goto loc_40022F2;
    }
loc_40022E4:
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
