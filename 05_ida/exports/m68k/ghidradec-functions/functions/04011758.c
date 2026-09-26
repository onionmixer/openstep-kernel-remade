
/* WARNING: Removing unreachable block (ram,0x0401179c) */

char * _nextc3(int *param_1,int param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*param_1 == 0) || (pcVar3 = (char *)(param_2 + 1), pcVar3 == (char *)param_1[2])) {
    pcVar3 = (char *)0x0;
  }
  else {
    if (((uint)pcVar3 & 0x3f) == 0) {
      pcVar3 = (char *)(*(int *)(param_2 + -0x3f) + 0xc);
    }
    cVar1 = *pcVar3;
    *param_3 = (int)cVar1;
    iVar2 = (int)((uint)pcVar3 & 0x3f) >> 3;
    if (((int)*(char *)(iVar2 + 4 + ((uint)pcVar3 & 0xffffffc0)) &
        1 << (((uint)pcVar3 & 0x3f) + iVar2 * -8 & 0x1f)) != 0) {
      *param_3 = CONCAT22(cVar1 >> 7,(sword)cVar1) | 0x100;
    }
  }
  return pcVar3;
}
