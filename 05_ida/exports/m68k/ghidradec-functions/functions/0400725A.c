
void _delete_posix_proc(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined auStack_54 [80];
  
  piVar1 = (int *)(_posix_proc_hash + (*(word *)(param_1 + 0x30) & 0x3f) * 4);
  iVar2 = *piVar1;
  while( true ) {
    if (iVar2 == 0) {
      _sprintf(auStack_54,aDeletePosixPro,(int)*(sword *)(param_1 + 0x30));
                    /* WARNING: Subroutine does not return */
      _panic(auStack_54);
    }
    piVar3 = (int *)*piVar1;
    if ((int)*(sword *)(param_1 + 0x30) == *piVar3) break;
    piVar1 = (int *)((int)piVar3 + 0x1a);
    iVar2 = *piVar1;
  }
  *piVar1 = *(int *)((int)piVar3 + 0x1a);
  _kfree(piVar3,0x1e);
  return;
}
