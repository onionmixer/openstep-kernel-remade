
void _binval(uint param_1)

{
  uint *puVar1;
  undefined *puVar2;
  
loc_4018500:
  puVar2 = _bufhash;
  do {
    for (puVar1 = *(uint **)((int)puVar2 + 4); (uint *)puVar2 != puVar1; puVar1 = (uint *)puVar1[1])
    {
      if ((param_1 == puVar1[0x10]) && ((*puVar1 & 0x10000) == 0)) {
        *puVar1 = *puVar1 | 0x10000;
        sub_4018584(puVar1);
        goto loc_4018500;
      }
    }
    puVar2 = (undefined *)((int)puVar2 + 0xc);
    if (_bufhash + 0xbf < puVar2) {
      return;
    }
  } while( true );
}

