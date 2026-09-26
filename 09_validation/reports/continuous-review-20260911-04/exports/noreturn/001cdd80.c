
void __objc_error(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar2 = _object_getClassName(param_1);
  _log(3,"objc error: %s ",uVar2);
  _vlog(3,param_2,param_3);
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (param_2[~uVar3 - 2] != '\n') {
    _log(3,"\n");
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

