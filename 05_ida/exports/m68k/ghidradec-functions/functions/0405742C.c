
void sub_405742C(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x76543) {
    puVar1 = (undefined4 *)_kalloc(0x14);
    puVar1[2] = *(undefined4 *)(param_1 + 0x1c);
    puVar1[3] = *(undefined4 *)(param_1 + 0x20);
    puVar1[4] = *(undefined4 *)(param_1 + 0x28);
    *dword_40B4DEC = puVar1;
    puVar1[1] = dword_40B4DEC;
    *puVar1 = &dword_40B4DE8;
    dword_40B4DEC = puVar1;
  }
  else {
    _printf(aNotifyServerBo,*(int *)(param_1 + 0x14));
  }
  return;
}
