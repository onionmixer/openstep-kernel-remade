
/* WARNING: Removing unreachable block (ram,0xf00ebd34) */
/* WARNING: Removing unreachable block (ram,0xf00ebcfc) */
/* WARNING: Removing unreachable block (ram,0xf00ebd4c) */
/* WARNING: Removing unreachable block (ram,0xf00ebd1c) */

undefined8 FUN_f00ebcfc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = param_1;
    _objc_msgSend(param_1,PTR_s_methodArgSize__f0141a20,param_3);
    if (iVar1 == 0) {
      _objc_msgSend(param_1,PTR_s_doesNotRecognize__f0141a24,param_3);
    }
    else {
      _objc_msgSendv(param_1,param_3,iVar1,param_4);
    }
  }
  return CONCAT44(param_2,param_1);
}

