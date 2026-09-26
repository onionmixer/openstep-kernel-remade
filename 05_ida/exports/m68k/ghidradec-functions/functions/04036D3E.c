
void sub_4036D3E(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (dword_40C10A0 == 0) {
    if (-1 < *(char *)(param_1 + 0xc)) {
      return;
    }
    iVar1 = (*dword_40C1090)(param_1);
    if (iVar1 != 0) {
      return;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0x7f;
    pcVar2 = dword_40C109C;
  }
  else {
    if ((char)*(byte *)(param_1 + 0xc) < '\0') {
      return;
    }
    if ((int *)(param_1 + 0xe) != *(int **)(param_1 + 0xe)) {
      return;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x80;
    pcVar2 = dword_40C1098;
  }
  (*pcVar2)(param_1);
  return;
}
