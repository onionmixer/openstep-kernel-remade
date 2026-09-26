
undefined4 * sub_40828DE(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = dword_40B5090;
  puVar1 = (undefined4 *)dword_40B5090[6];
  if ((undefined4 **)puVar1 == &dword_40B5090) {
    dword_40B5094 = &dword_40B5090;
  }
  else {
    puVar1[7] = &dword_40B5090;
  }
  *dword_40B5090 = 4;
  dword_40B5090 = puVar1;
  puVar2[1] = (int)puVar2 + 0x26;
  puVar2[3] = (int)puVar2 + 0x26;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 1;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
