
/* Entry confirmed from original binary metadata: original symbol __objc_msgForward */

void __objc_msgForward(undefined4 param_1,undefined *param_2)

{
  if (param_2 != PTR_s_forward__001f9cf0) {
    _objc_msgSend(param_1,PTR_s_forward__001f9cf0,param_2,&param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___objc_error(param_1,"Does not recognize selector %s",s_forward___00207584);
}

