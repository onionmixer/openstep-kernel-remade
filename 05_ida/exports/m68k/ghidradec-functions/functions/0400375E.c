
void _add_profil(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _active_u;
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (*(int *)(_active_u + 0x250) != 0) {
    iVar3 = _kalloc(0x18);
    *(undefined4 *)(iVar3 + 8) = *puVar1;
    *(undefined4 *)(iVar3 + 0xc) = puVar1[1];
    *(undefined4 *)(iVar3 + 0x10) = puVar1[2];
    *(undefined4 *)(iVar3 + 0x14) = puVar1[3];
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar2 + 0x240);
    *(int *)(iVar2 + 0x240) = iVar3;
  }
  return;
}
