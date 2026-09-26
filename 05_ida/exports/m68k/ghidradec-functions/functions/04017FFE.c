
uint * _getnewbuf(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  do {
    puVar2 = &unk_40B5860;
    do {
      if (puVar2 != (undefined4 *)puVar2[3]) break;
      puVar2 = puVar2 + -0x11;
    } while (&_bfreelist < puVar2);
    if (puVar2 == &_bfreelist) {
      _bfreelist = _bfreelist | 0x40;
      _sleep(&_bfreelist,0x15);
    }
    else {
      puVar1 = (uint *)puVar2[3];
      *(uint *)(puVar1[4] + 0xc) = puVar1[3];
      *(uint *)(puVar1[3] + 0x10) = puVar1[4];
      *puVar1 = *puVar1 | 8;
      if ((*puVar1 & 0x200) == 0) {
        *puVar1 = 8;
        return puVar1;
      }
      *puVar1 = *puVar1 | 0x100;
      _bwrite(puVar1);
    }
  } while( true );
}
