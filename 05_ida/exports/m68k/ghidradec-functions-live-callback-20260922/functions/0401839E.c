
byte _binvalfree(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
loc_40183AA:
  puVar2 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar2[3]; puVar2 != puVar1; puVar1 = (uint *)puVar1[3]) {
      if ((param_1 == puVar1[0x10]) || (param_1 == 0)) {
        if ((*puVar1 & 0x200) == 0) {
          *puVar1 = *puVar1 | 0x10000;
          sub_4018584(puVar1);
        }
        else {
          puVar1[0xc] = (uint)_brelvp_wakeup;
          *puVar1 = *puVar1 | 0x200100;
          *(uint *)(puVar1[4] + 0xc) = puVar1[3];
          *(uint *)(puVar1[3] + 0x10) = puVar1[4];
          *puVar1 = *puVar1 | 8;
          _bwrite(puVar1);
        }
        goto loc_40183AA;
      }
    }
    puVar3 = puVar2 + 0x11;
    puVar1 = puVar2 + -0x102d618;
    puVar2 = puVar3;
    if (&DAT_40b58a3 < puVar3) {
      return ((int)puVar1 < 0) << 3 | (puVar3 == (uint *)((int)&DAT_40b58a3 + 1)) << 2 |
             SBORROW4((int)puVar3,0x40b58a4) << 1;
    }
  } while( true );
}

