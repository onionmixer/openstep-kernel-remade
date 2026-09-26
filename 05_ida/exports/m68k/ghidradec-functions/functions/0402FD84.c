
void sub_402FD84(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)0x0;
  puVar2 = *(uint **)(_drhashtbl + (*param_1 & 0x1f) * 4);
  while( true ) {
    if (puVar2 == (uint *)0x0) {
      return;
    }
    if (param_1 == puVar2) break;
    puVar1 = puVar2;
    puVar2 = (uint *)puVar2[9];
  }
  if (puVar1 == (uint *)0x0) {
    *(uint *)(_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2[9];
    return;
  }
  puVar1[9] = puVar2[9];
  return;
}
