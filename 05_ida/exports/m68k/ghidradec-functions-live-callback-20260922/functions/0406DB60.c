
void _fd_done(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)_disksort_first(param_1 + 0xba);
  if (puVar1 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSddoneNoBufOnS);
  }
  puVar1[10] = *(uint *)(param_1 + 0x140);
  if (*(int *)(param_1 + 0x9e) != 0) {
    if (*(int *)(param_1 + 0x9e) == 0x14) {
      *(undefined2 *)(puVar1 + 7) = 6;
    }
    else {
      *(undefined2 *)(puVar1 + 7) = 5;
    }
  }
  if (*(sword *)(puVar1 + 7) != 0) {
    *puVar1 = *puVar1 | 4;
  }
  _disksort_remove(param_1 + 0xba,puVar1);
  if ((uint *)(param_1 + 0x18) == puVar1) {
    _bcopy(param_1 + 0x60,*(undefined4 *)(param_1 + 0x5c),0x5a);
  }
  _biodone(puVar1);
  *(undefined4 *)(param_1 + 0x132) = 0;
  iVar2 = _disksort_first(param_1 + 0xba);
  if (iVar2 != 0) {
    _fd_start(param_1);
  }
  return;
}

