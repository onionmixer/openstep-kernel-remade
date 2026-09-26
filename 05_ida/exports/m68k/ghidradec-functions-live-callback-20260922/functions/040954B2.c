
int _dbg_kresume(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = _dbg_setjmp(unk_40B55CC);
  puVar1 = dword_40C9714;
  if (iVar2 == 0) {
    dword_40C9714 = dword_40C9714 + -4;
    *dword_40C9714 = word_40C971A;
    *(undefined4 *)(puVar1 + -3) = dword_40C971C;
    *(byte *)(puVar1 + -1) = *(byte *)(puVar1 + -1) & 0xf;
    dword_40B5610 = unk_40B55CC;
    iVar2 = __dbg_kresume();
  }
  return iVar2;
}

