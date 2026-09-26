
undefined4 * sub_408298E(undefined4 param_1,undefined4 param_2)

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
  *dword_40B5090 = 8;
  dword_40B5090 = puVar1;
  puVar2[1] = param_1;
  puVar2[2] = param_2;
  *(undefined *)(puVar2 + 8) = 0;
  *(undefined *)(puVar2 + 9) = 1;
  *(undefined *)((int)puVar2 + 0x23) = 0;
  *(undefined *)((int)puVar2 + 0x22) = 1;
  return puVar2;
}
