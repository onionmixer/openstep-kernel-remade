
undefined4 _makefh(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  word *pwStack_8;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 100))(param_2,&pwStack_8);
  if ((iVar1 == 0) && (pwStack_8 != (word *)0x0)) {
    if (*pwStack_8 + 8 + (uint)**(word **)(param_3 + 0x28) < 0x21) {
      _bzero(param_1,0x20);
      *param_1 = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(word *)(param_1 + 2) = *pwStack_8;
      _bcopy(pwStack_8 + 1,(int)param_1 + 10,*pwStack_8);
      *(undefined2 *)(param_1 + 5) = **(undefined2 **)(param_3 + 0x28);
      _bcopy(*(int *)(param_3 + 0x28) + 2,(int)param_1 + 0x16,*(undefined2 *)(param_1 + 5));
      _kfree(pwStack_8,*pwStack_8 + 2);
      return 0;
    }
    _kfree(pwStack_8,*pwStack_8 + 2);
  }
  return 0x47;
}

