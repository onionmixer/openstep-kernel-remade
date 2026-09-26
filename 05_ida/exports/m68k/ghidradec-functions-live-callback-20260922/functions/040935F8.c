
void _machparam(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined uVar4;
  undefined4 *puVar5;
  undefined auStack_28 [4];
  undefined auStack_24 [32];
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar3 = _suser();
  if (iVar3 != 0) {
    uVar4 = _copyinstr(*puVar1,auStack_24,0x20,auStack_28);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      for (puVar5 = &_kernargs; *(char *)*puVar5 != '\0'; puVar5 = puVar5 + 3) {
        iVar3 = _strcmp((char *)*puVar5,auStack_24);
        if (iVar3 == 0) {
          piVar2 = (int *)puVar5[1];
          if (piVar2 != (int *)0x0) {
            *piVar2 = puVar1[1] + *piVar2;
            return;
          }
          *(char *)(_slot_id_bmap + puVar5[2]) =
               *(char *)((int)puVar1 + 7) + *(char *)(_slot_id_bmap + puVar5[2]);
          return;
        }
      }
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}

