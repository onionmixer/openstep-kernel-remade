
void _nitro_cache_flush(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (_cache != 0) {
    if (dword_40B4F52 == 0) {
      dword_40B4F52 = 1;
      if ((*(uint *)(_slot_id + 0x2210000) & 0x11e) == 0) {
        dword_40B4F56 = 0x20000;
        *(undefined4 *)(_slot_id + 0x2210000) = 0x10c;
      }
      else {
        uVar1 = *(uint *)(_slot_id + 0x2210000) & 0x18;
        if (uVar1 == 8) {
          dword_40B4F56 = 0x20000;
        }
        else if (uVar1 < 9) {
          if (uVar1 == 0) {
            dword_40B4F56 = 0x10000;
          }
        }
        else if (uVar1 == 0x10) {
          dword_40B4F56 = 0x40000;
        }
        else if (uVar1 == 0x18) {
          dword_40B4F56 = 0x80000;
        }
      }
      iVar3 = 0;
      if (0 < dword_40B4F56) {
        do {
          *(undefined4 *)(_slot_id + iVar3 + 0x3e00000) = 0;
          iVar3 = iVar3 + 0x20;
        } while (iVar3 < dword_40B4F56);
      }
      *(uint *)(_slot_id + 0x2210000) = *(uint *)(_slot_id + 0x2210000) | 1;
    }
    uVar1 = dword_40B4F56 - 1;
    uVar4 = 0;
    uVar2 = param_2 + 0x1fU >> 5;
    if (uVar2 != 0) {
      do {
        *(undefined4 *)(_slot_id + (uVar1 & param_1) + uVar4 * 0x20 + 0x3e00000) = 0;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return;
}
