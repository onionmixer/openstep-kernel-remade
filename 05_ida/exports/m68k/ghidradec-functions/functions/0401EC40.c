
void _inet_hash(int param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = _in_netof(*(undefined4 *)(param_1 + 4));
  if (uVar1 != 0) {
    cVar2 = (char)uVar1;
    while (cVar2 == '\0') {
      cVar2 = (char)(uVar1 >> 8);
      uVar1 = uVar1 >> 8;
    }
  }
  param_2[1] = uVar1;
  *param_2 = *(undefined4 *)(param_1 + 4);
  return;
}
