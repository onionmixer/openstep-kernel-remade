
undefined4 _lf_lockctl(undefined4 param_1,sword *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = sub_40386C0(param_1);
  puVar2 = (undefined2 *)_kalloc(0x1c);
  puVar2[1] = *param_2;
  *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_2 + 2);
  if (*(int *)(param_2 + 4) == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(param_2 + 2) + *(int *)(param_2 + 4) + -1;
  }
  *(int *)(puVar2 + 4) = iVar3;
  uVar4 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  *(undefined4 *)(puVar2 + 6) = uVar4;
  *(int *)(puVar2 + 8) = iVar1;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(undefined4 *)(puVar2 + 10) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  if (param_3 == 7) {
    uVar4 = sub_4038B30(puVar2,param_2);
    sub_4038E3A(puVar2);
  }
  else {
    if (*param_2 != 3) {
      if (param_3 == 8) {
        *puVar2 = 1;
      }
      else {
        *puVar2 = 2;
      }
      uVar4 = sub_403878C(puVar2);
      return uVar4;
    }
    uVar4 = sub_4038A24(puVar2);
    sub_4038E3A(puVar2);
  }
  sub_4038728(iVar1);
  return uVar4;
}
