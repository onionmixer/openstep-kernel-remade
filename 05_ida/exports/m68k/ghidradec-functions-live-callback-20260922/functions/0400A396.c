
void _adjtime(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    uVar3 = _copyinmsg(*puVar1,&uStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _host_adjust_time(dword_40B67DC,uStack_c,uStack_8,&uStack_14);
      if (puVar1[1] != 0) {
        uStack_1c = uStack_14;
        uStack_18 = uStack_10;
        _copyoutmsg(&uStack_1c,puVar1[1],8);
      }
    }
  }
  return;
}

