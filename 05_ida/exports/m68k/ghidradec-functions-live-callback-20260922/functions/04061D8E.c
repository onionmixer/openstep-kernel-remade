
int _procdup(int param_1,int param_2)

{
  int iVar1;
  int iStack_c;
  int iStack_8;
  
  iVar1 = _task_create(*(int *)(param_2 + 0x66),*(int *)(param_2 + 0x66) != _kernel_task,&iStack_8);
  if (iVar1 != 0) {
    _printf(aForkProcdupTas,iVar1);
  }
  *(int *)(param_1 + 0x66) = iStack_8;
  _task_deallocate(iStack_8);
  *(int *)(iStack_8 + 0x34) = param_1;
  iVar1 = _thread_create(iStack_8,&iStack_c);
  if (iVar1 != 0) {
    _printf(aForkProcdupThr,iVar1);
  }
  _thread_deallocate(iStack_c);
  _compute_priority(iStack_c,0);
  _bcopy(*(undefined4 *)(*(int *)(param_2 + 0x66) + 0x30),*(undefined4 *)(iStack_8 + 0x30),0x28a);
  _bzero(*(int *)(iStack_8 + 0x30) + 0x23c,0x18);
  *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x152) = 0;
  _expand_fdlist(*(int *)(iStack_8 + 0x30),*(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x14e));
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x66) + 0x30) + 0x146),
         *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x146),
         (*(int *)(*(int *)(iStack_8 + 0x30) + 0x14e) + 1) * 4);
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x66) + 0x30) + 0x14a),
         *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x14a),
         *(int *)(*(int *)(iStack_8 + 0x30) + 0x14e) + 1);
  **(int **)(*(int *)(iStack_c + 0xc) + 0x30) = param_1;
  _bzero(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x166,0x48);
  _bzero(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x1ae,0x48);
  *(undefined4 *)(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x26) = 0;
  return iStack_c;
}

