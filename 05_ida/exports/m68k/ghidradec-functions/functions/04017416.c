
int _vafsidtovfs(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iStack_42;
  undefined auStack_3e [10];
  int iStack_34;
  
  puVar1 = _rootvfs;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0x16;
    }
    iVar2 = (**(code **)(puVar1[1] + 8))(puVar1,&iStack_42);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*(int *)(iStack_42 + 0x1c) + 0x14))
                      (iStack_42,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1 == iStack_34) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  *param_2 = puVar1;
  return 0;
}

