
void _uname(void)

{
  int *piVar1;
  undefined uVar2;
  int iVar3;
  undefined *puVar4;
  undefined auStack_28 [4];
  undefined auStack_24 [32];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  uVar2 = _copyoutstr(aNextstep,*piVar1,0x20,auStack_28);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = _copyoutstr(_hostname,*piVar1 + 0x20,0x20,auStack_28);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _sprintf(auStack_24,&aD_0,0);
      uVar2 = _copyoutstr(auStack_24,*piVar1 + 0x40,0x20,auStack_28);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _sprintf(auStack_24,&aD_0,4);
        uVar2 = _copyoutstr(auStack_24,*piVar1 + 0x60,0x20,auStack_28);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          switch(_machine_type) {
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextCube;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextWarp9;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextX15;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextWarp9c;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbo;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurboc;
            break;
          :
            iVar3 = *piVar1 + 0x80;
            puVar4 = (undefined *)&aUnknown;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbocube;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbocubec;
          }
          uVar2 = _copyoutstr(puVar4,iVar3,0x20,auStack_28);
          *(undefined *)(dword_40B57D4 + 100) = uVar2;
        }
      }
    }
  }
  return;
}
