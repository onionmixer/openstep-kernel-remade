
undefined4 _dspq_check(void)

{
  uint uVar1;
  
  if (dword_40C6E76 == 7) {
    return 0;
  }
  if (dword_40C6E72 != 0) {
    if (_cpu_type == '\0') {
      uVar1 = *(uint *)(_slot_id_bmap + 0x2008000);
    }
    else {
      uVar1 = CONCAT31((uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18) >> 8) |
                       (uint3)(((uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10) >> 8) |
                       (uint3)*(byte *)(_slot_id_bmap + 0x2008002),
                       *(undefined *)(_slot_id_bmap + 0x2008003));
    }
    if ((dword_40C6E6A & uVar1) == dword_40C6E6E) {
      return 1;
    }
  }
  if (((((dword_40C6E84 & 0x10000) == 0) || (dword_40C6DFC == 0)) ||
      (dword_40C6DFC + 0x3e == *(int *)(dword_40C6DFC + 0x3e))) ||
     ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) == 0)) {
    if ((undefined4 **)dword_40C6E46 == &dword_40C6E46) {
      return 0;
    }
    switch(*dword_40C6E46) {
    case :
      if (_cpu_type == '\0') {
        uVar1 = *(uint *)(_slot_id_bmap + 0x2008000);
      }
      else {
        uVar1 = (uint)*(byte *)(_slot_id_bmap + 0x2008000) << 0x18 |
                (uint)*(byte *)(_slot_id_bmap + 0x2008001) << 0x10;
        do {
          uVar1 = uVar1 & 0xffff00ff | (uint)*(byte *)(_slot_id_bmap + 0x2008002) << 8;
        } while (*(byte *)(_slot_id_bmap + 0x2008002) != *(byte *)(_slot_id_bmap + 0x2008002));
        uVar1 = CONCAT31((int3)(uVar1 >> 8),*(undefined *)(_slot_id_bmap + 0x2008003));
      }
      if ((dword_40C6E46[1] & uVar1) != dword_40C6E46[2]) {
        return 0;
      }
      break;
    case :
    case :
    case :
    case :
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 2) == 0) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
        return 0;
      }
      if ((((dword_40C6E76 != 5) || (*(char *)((int)dword_40C6E46 + 0x21) == '\x01')) ||
          (*(char *)(dword_40C6E46 + 8) != '\0')) &&
         (((dword_40C6E76 == 4 || (dword_40C6E76 == 5)) || (dword_40C6E76 == 6)))) {
        return 0;
      }
      break;
    case :
    case :
      if (dword_40C6E76 != 0) {
        return 0;
      }
      break;
    case :
      if (*(char *)(_slot_id_bmap + 0x2008001) < '\0') {
        return 0;
      }
      break;
    case :
      if (dword_40C6E76 != 0) {
        return 0;
      }
      break;
    case :
    case :
    case :
    case :
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 1) == 0) {
        *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
        return 0;
      }
      if (((dword_40C6E76 == 1) || (dword_40C6E76 == 2)) || (dword_40C6E76 == 3)) {
        return 0;
      }
    }
  }
  return 1;
}

