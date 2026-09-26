
undefined4 _if_handle_input(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ifnet;
  while( true ) {
    if (iVar1 == 0) {
      _nb_free(param_2);
      return 0x2f;
    }
    if (((*(code **)(iVar1 + 0x3a) != (code *)0x0) && (*(int *)(iVar1 + 0x12) != 0)) &&
       (iVar2 = (**(code **)(iVar1 + 0x3a))(iVar1,param_1,param_2,param_3), iVar2 == 0)) break;
    iVar1 = *(int *)(iVar1 + 0x5a);
  }
  return 0;
}

