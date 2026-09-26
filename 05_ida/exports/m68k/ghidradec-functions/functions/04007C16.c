
sword * _crget(void)

{
  sword *psVar1;
  
  psVar1 = (sword *)_kalloc(0x2a);
  _bzero(psVar1,0x2a);
  *psVar1 = *psVar1 + 1;
  _cractive = _cractive + 1;
  return psVar1;
}
