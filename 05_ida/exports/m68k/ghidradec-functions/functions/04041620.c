
int _ipc_pset_alloc_name(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _ipc_object_alloc_name(param_1,1,0x80000,0,param_2,&iStack_8);
  if (iVar1 == 0) {
    *(undefined4 *)(iStack_8 + 8) = param_2;
    _ipc_mqueue_init(iStack_8 + 0xc);
    *param_3 = iStack_8;
    iVar1 = 0;
  }
  return iVar1;
}
