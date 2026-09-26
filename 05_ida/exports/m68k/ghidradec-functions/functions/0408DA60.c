
undefined4 * _enbuf_get(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((dword_40B244A == (undefined4 *)0x0) && (iVar2 = sub_408D9D4(), iVar2 != 0)) {
    return (undefined4 *)0x0;
  }
  puVar1 = dword_40B244A;
  dword_40B2452 = dword_40B2452 + -1;
  dword_40B244A = (undefined4 *)*dword_40B244A;
  return puVar1;
}
