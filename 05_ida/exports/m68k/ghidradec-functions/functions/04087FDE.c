
void sub_4087FDE(undefined4 param_1)

{
  int iVar1;
  int iStack_8;
  
  _lock_write(dword_40C6EBC);
  *(int *)(dword_40C6EBC + 0x40) = *(int *)(dword_40C6EBC + 0x40) + 1;
  iVar1 = _vm_map_lookup_entry(dword_40C6EBC,param_1,&iStack_8);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSndWirePageAdd);
  }
  *(sword *)(iStack_8 + 0x26) = *(sword *)(iStack_8 + 0x26) + 1;
  _lock_done(dword_40C6EBC);
  _vm_fault(dword_40C6EBC,param_1,0,1,0);
  _lock_write(dword_40C6EBC);
  *(int *)(dword_40C6EBC + 0x40) = *(int *)(dword_40C6EBC + 0x40) + 1;
  *(sword *)(iStack_8 + 0x26) = *(sword *)(iStack_8 + 0x26) + -1;
  _lock_done(dword_40C6EBC);
  return;
}
