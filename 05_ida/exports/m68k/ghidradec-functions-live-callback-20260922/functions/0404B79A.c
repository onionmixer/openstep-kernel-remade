
int _getsegbyname(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _getsegbynamefromheader(0x4000000,param_1);
  if (iVar1 == 0) {
    iVar2 = _strcmp(param_1,_fvm_seg + 8);
    if (iVar2 == 0) {
      iVar1 = _fvm_seg;
    }
  }
  return iVar1;
}

