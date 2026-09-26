
int _ipc_pset_alloc(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iStack_c;
  undefined4 uStack_8;
  
  iVar1 = _ipc_object_alloc(param_1,1,0x80000,0,&uStack_8,&iStack_c);
  if (iVar1 == 0) {
    *(undefined4 *)(iStack_c + 8) = uStack_8;
    _ipc_mqueue_init(iStack_c + 0xc);
    *param_2 = uStack_8;
    *param_3 = iStack_c;
    iVar1 = 0;
  }
  return iVar1;
}

