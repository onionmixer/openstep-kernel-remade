
void _thread_dup(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
    uVar1 = _thread_user_state(param_1);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x48);
  }
  piVar2 = (int *)_thread_user_state(param_2);
  _bcopy(uVar1,piVar2,0x48);
  *piVar2 = (int)*(sword *)(*(int *)(*(int *)(param_2 + 0xc) + 0x34) + 0x30);
  piVar2[1] = 1;
  *(word *)(piVar2 + 0x10) = *(word *)(piVar2 + 0x10) & 0x3ffe;
  if (piVar2[0xf] != piVar2[8]) {
    piVar2[0xf] = piVar2[0xf] + 4;
  }
  return;
}
