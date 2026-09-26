
undefined4 _ns_untimeout(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = &_ns_calltodo;
  puVar2 = _ns_calltodo;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = _callout_remove(param_1,param_2);
      return uVar3;
    }
    if ((param_1 == puVar2[4]) && (param_2 == puVar2[3])) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar1 = *puVar2;
  *puVar2 = _ns_callfree;
  _ns_callfree = puVar2;
  return 1;
}
