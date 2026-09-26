
void _dnlc_purge_vp(int param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  
  do {
    bVar2 = false;
    for (puVar1 = dword_40B6D68; puVar1 != &_nc_lru; puVar1 = *(undefined8 **)(puVar1 + 1)) {
      if ((param_1 == *(int *)((int)puVar1 + 0x14)) || (param_1 == *(int *)(puVar1 + 2))) {
        sub_4018AFE(puVar1);
        bVar2 = true;
        break;
      }
    }
    if (!bVar2) {
      return;
    }
  } while( true );
}

