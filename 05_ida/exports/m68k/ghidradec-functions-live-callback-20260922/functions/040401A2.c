
int _ipc_object_translate(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint *puStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    if ((1 << (param_3 + 0x10U & 0x3f) & *puStack_8) == 0) {
      iVar1 = 0x11;
    }
    else {
      *param_4 = puStack_8[1];
      iVar1 = 0;
    }
  }
  return iVar1;
}

