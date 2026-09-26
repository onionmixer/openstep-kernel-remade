
/* WARNING: Control flow encountered bad instruction data */

undefined8 trap3(void)

{
  code *pcVar1;
  int iVar2;
  int in_D0;
  sword sVar3;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  dword_40B5658 = dword_40B5658 + 1;
  puVar5 = _stack_pointers;
  uStack_3c = in_D1;
  if ((in_D0 < 0) || (_mach_trap_count <= in_D0)) {
    uStack_40 = 4;
  }
  else {
    sVar3 = (sword)in_D0 << 4;
    puVar4 = _stack_pointers;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(sVar3) {
    case :
      puVar4 = _stack_pointers + -4;
      *(undefined4 *)(_stack_pointers + -4) = unaff_D7;
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = unaff_D6;
    case :
    case :
      puVar4 = puVar5 + -4;
      *(undefined4 *)(puVar5 + -4) = unaff_D5;
    case :
    case :
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = unaff_D4;
    case :
      *(undefined4 *)(puVar5 + -4) = unaff_D3;
      puVar4 = puVar5 + -8;
      *(undefined4 *)(puVar5 + -8) = unaff_D2;
    case :
    case :
    case :
    case :
    case :
      puVar5 = puVar4 + -4;
      *(undefined4 *)(puVar4 + -4) = in_D1;
    :
      pcVar1 = *(code **)(_mach_trap_table + sVar3 + 4);
      *(undefined4 *)(puVar5 + -4) = 0x4001e7e;
      uStack_40 = (*pcVar1)();
      break;
    case :
      return CONCAT44(*(undefined4 *)(_mach_trap_table + sVar3),in_D1);
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case :
      return CONCAT44(*(undefined4 *)(_mach_trap_table + sVar3),in_D1);
    case :
    case :
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if ((((*(byte *)(*(int *)(_active_threads + 0x24) + 0x54) & 0x10) != 0) ||
      (iVar2 = **(int **)(*(int *)(_active_threads + 0xc) + 0x30), *(char *)(iVar2 + 0x17) != '\0'))
     || (*(int *)(iVar2 + 0x18) != 0)) {
    *(undefined4 **)(puVar5 + -4) = &uStack_40;
    *(undefined4 *)(puVar5 + -8) = 0x4001eb4;
    _check_for_ast();
  }
  return CONCAT44(uStack_40,uStack_3c);
}

