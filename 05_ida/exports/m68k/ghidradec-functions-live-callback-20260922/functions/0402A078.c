
int sub_402A078(undefined4 param_1,char *param_2,undefined2 *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iStack_20;
  undefined *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  puStack_1c = _hostname;
  uStack_18 = param_1;
  _bzero(&uStack_14,0x10);
  iVar1 = sub_4029D46();
  if (iVar1 == 0) {
    uStack_14 = _kalloc(0x100);
    uStack_8 = _kalloc(0x100);
    iVar1 = 0;
    do {
      iVar2 = sub_4029C74(unk_40B3554,0x186ba,1,2,_xdr_bp_getfile_arg,&puStack_1c,
                          _xdr_bp_getfile_res,&uStack_14,5,0,0);
      if (iVar2 != 5) break;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
    if (iVar2 == 0) {
      _strcpy(param_2,uStack_14);
      _strcpy(param_4,uStack_8);
    }
    _kfree(uStack_14,0x100);
    _kfree(uStack_8,0x100);
    if (iVar2 == 0) {
      _bcopy(auStack_c,&iStack_20,4);
      if (((*param_2 == '\0') || (*param_4 == '\0')) || (iStack_20 == 0)) {
        iVar1 = 0x16;
      }
      else if (iStack_10 == 1) {
        _bzero(param_3,0x10);
        *param_3 = 2;
        *(int *)(param_3 + 2) = iStack_20;
        _printf(aNfsMountingSFr,param_1,param_2,param_4);
        iVar1 = 0;
      }
      else {
        _printf(aGetfileUnknown,iStack_10);
        iVar1 = 0x2b;
      }
    }
    else {
      iVar1 = 0x3c;
      if (iVar2 != 5) {
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}

