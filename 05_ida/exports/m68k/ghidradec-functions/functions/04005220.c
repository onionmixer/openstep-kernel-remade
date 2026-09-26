
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _load_init_program(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar2 = 0;
  do {
    if ((__boothowto & 0x10) != 0) {
      _printf(aInitProgram);
      _gets(_init_program_name,_init_program_name);
    }
    if (((iVar2 != 0) && ((__boothowto & 0x10) == 0)) && (_init_attempts == 1)) {
      _printf(aLoadOfSErrnoDT,_init_program_name,iVar2,aEtcInit);
      iVar2 = 0;
      _bcopy(aEtcInit,_init_program_name,10);
    }
    _init_attempts = _init_attempts + 1;
    if (iVar2 == 0) {
      uStack_14 = 0;
      _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_14,_page_size,1);
      if (uStack_14 == 0) {
        uStack_14 = 1;
      }
      _copyoutmsg(_init_program_name,uStack_14,0x81);
      uStack_10 = uStack_14;
      uStack_14 = uStack_14 + 0x8f & 0xfffffff0;
      _copyoutmsg(&_init_args,uStack_14,0x80);
      uStack_c = uStack_14;
      uStack_14 = uStack_14 + 0x8f & 0xfffffff0;
      uStack_8 = 0;
      _copyoutmsg(&uStack_10,uStack_14,0xc);
      _init_exec_args = uStack_10;
      dword_40B6074 = uStack_14;
      dword_40B6078 = 0;
      uVar1 = *(undefined4 *)(dword_40B57D4 + 0x24);
      *(uint **)(dword_40B57D4 + 0x24) = &_init_exec_args;
      iVar2 = _execve();
      *(undefined4 *)(dword_40B57D4 + 0x24) = uVar1;
    }
    else {
      _printf(aLoadOfSFailedE,_init_program_name,iVar2);
      iVar2 = 0;
      __boothowto = __boothowto | 0x10;
    }
  } while (iVar2 != 0);
  return;
}
