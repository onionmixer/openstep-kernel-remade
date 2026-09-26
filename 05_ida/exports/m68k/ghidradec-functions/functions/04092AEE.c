
void _pmonlogcontext(undefined4 param_1,undefined4 param_2,int param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_3 != _vm_saved_context_thread) {
    _vm_saved_context_flushed = 0;
    _vm_saved_context_thread = param_3;
    _vm_saved_context_data0 = uRam040c32c2;
    _vm_saved_context_data1 = uRam040c2c0e;
    pcVar3 = param_4 + 1;
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    iVar2 = 0;
    do {
      pcVar3 = pcVar3 + -1;
      if (pcVar3 <= param_4) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    _strncpy(&_vm_saved_context_name,pcVar3,0xc);
  }
  return;
}
