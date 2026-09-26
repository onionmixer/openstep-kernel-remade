
undefined4 sub_406CFE8(int *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *param_1;
  if (_fd_polling_mode == 0) {
    if ((param_1[6] & 8U) == 0) {
      do {
        if (*(char *)(iVar1 + 4) < '\0') {
          if ((param_2 | 0x80) != (*(byte *)(iVar1 + 4) & 0xc0)) {
            uVar3 = 10;
          }
          break;
        }
      } while ((param_1[6] & 8U) == 0);
    }
    if ((param_1[6] & 8U) == 0) {
      return uVar3;
    }
  }
  else {
    iVar2 = 0;
    do {
      if (*(char *)(iVar1 + 4) < '\0') {
        if ((param_2 | 0x80) != (*(byte *)(iVar1 + 4) & 0xc0)) {
          return 10;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1000000);
    if (iVar2 != 1000000) {
      return 0;
    }
  }
  return 1;
}

