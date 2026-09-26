
void _od_update(void)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = _od_vol;
  puVar3 = unk_40C3FA0;
  do {
    if ((*(word *)puVar3 & 0xf004) == 0xf000) {
      puVar2 = (uint *)(puVar4 + 0x6a);
      while ((*puVar2 & 8) != 0) {
        *puVar2 = *puVar2 | 0x40;
        _sleep(puVar2,0x14);
      }
      *puVar2 = 8;
      *(word *)puVar3 = *(word *)puVar3 | 0x400;
      _od_write_label(puVar4,0x7f);
      if ((*(word *)puVar3 & 0x200) != 0) {
        _wakeup(puVar4);
      }
      *(word *)puVar3 = *(word *)puVar3 & 63999;
      uVar1 = *puVar2;
      *puVar2 = uVar1 & 0xfffffff7;
      if ((uVar1 & 0x40) != 0) {
        _wakeup(puVar2);
      }
    }
    if (((sword)*(word *)puVar3 < 0) &&
       (*(word *)puVar3 = *(word *)puVar3 & 0xefff, (*(word *)puVar3 & 0x800) != 0)) {
      _od_cmd((int)(puVar4 + -0x40c3ec8) * 0x69b02594,0xf6,0,0,0,0,0,0,0,0);
    }
    puVar3 = (undefined *)((int)puVar3 + 0xda);
    puVar4 = puVar4 + 0xda;
  } while (puVar4 < (undefined *)0x40c592e);
  return;
}
