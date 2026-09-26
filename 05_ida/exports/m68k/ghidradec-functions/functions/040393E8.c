
void _bufstats(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int aiStack_c [2];
  
  puVar5 = &_bfreelist;
  iVar3 = 0;
  do {
    iVar4 = 0;
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      aiStack_c[iVar2] = 0;
    }
    for (puVar1 = (undefined4 *)puVar5[3]; puVar5 != puVar1; puVar1 = (undefined4 *)puVar1[3]) {
      aiStack_c[(int)puVar1[6] / _m68k_page_size] = aiStack_c[(int)puVar1[6] / _m68k_page_size] + 1;
      iVar4 = iVar4 + 1;
    }
    _printf(aSTotalD,*(undefined4 *)(unk_40AF326 + iVar3 * 4),iVar4);
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      if (aiStack_c[iVar2] != 0) {
        _printf(&aDD,iVar2 * _m68k_page_size,aiStack_c[iVar2]);
      }
    }
    _printf(&asc_40A6049);
    puVar5 = puVar5 + 0x11;
    iVar3 = iVar3 + 1;
  } while (puVar5 < &_buf);
  return;
}
