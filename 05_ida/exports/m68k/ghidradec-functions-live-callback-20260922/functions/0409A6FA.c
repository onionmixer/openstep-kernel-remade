
int _move_space(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_D6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar5 = _active_threads;
  iVar2 = *(int *)(param_5 + 0x42);
  iVar1 = *_active_u;
  if (iVar1 != 0) {
    unaff_D6 = *dword_40B57D4;
    *dword_40B57D4 = param_5;
  }
  uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x48);
  *(int *)(*(int *)(iVar5 + 0x24) + 0x48) = param_5;
  while( true ) {
    iVar6 = __move_space(param_1,param_2,param_3,param_4,&uStack_8,&uStack_c,&uStack_10);
    if ((iVar6 == 0) || ((param_2 & 0xfffffffc) != 0)) break;
    _exception_from_kernel(uStack_8,uStack_c,uStack_10);
    if ((((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) ||
        (iVar2 != *(int *)(param_5 + 0x42))) ||
       (((iVar1 != 0 && ((*(uint *)(iVar5 + 0x177) & 0x3ffffff) >> 0x18 == 0)) &&
        ((*(char *)(iVar1 + 0x17) != '\0' ||
         ((uVar4 = *(uint *)(*(int *)(iVar5 + 0x80) + 0x72) | *(uint *)(iVar1 + 0x18), uVar4 != 0 &&
          (((*(byte *)(iVar1 + 0x2b) & 0x10) != 0 ||
           ((uVar4 & ~(*(uint *)(iVar1 + 0x1c) | *(uint *)(iVar1 + 0x20))) != 0)))))))))) break;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0x48) = uVar3;
  if (iVar1 != 0) {
    *dword_40B57D4 = unaff_D6;
  }
  return iVar6;
}

