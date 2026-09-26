
undefined4 * _authkern_create(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x28);
  _bzero(puVar1,0x28);
  puVar1[8] = &DAT_040aef6a;
  *puVar1 = 1;
  puVar1[3] = __null_auth;
  puVar1[4] = DAT_040bc128;
  puVar1[5] = DAT_040bc12c;
  return puVar1;
}

