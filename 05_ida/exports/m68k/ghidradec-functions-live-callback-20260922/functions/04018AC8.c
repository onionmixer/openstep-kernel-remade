
undefined4 _dnlc_purge1(void)

{
  undefined8 *puVar1;
  
  puVar1 = dword_40B6D68;
  while( true ) {
    if (puVar1 == &_nc_lru) {
      return 0;
    }
    if (*(int *)((int)puVar1 + 0x14) != 0) break;
    puVar1 = *(undefined8 **)(puVar1 + 1);
  }
  sub_4018AFE(puVar1);
  return 1;
}

