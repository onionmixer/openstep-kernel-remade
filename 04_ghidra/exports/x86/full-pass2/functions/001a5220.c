/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5220 */

char * FUN_001a5220(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uStackY_2c;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  uVar7 = 0xffffffff;
  pcVar4 = param_3;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  iVar3 = -(uVar7 + 5 & 0xfffffffc);
  (&stack0xffffffe8)[iVar3] = 0x22;
  *(char **)(&stack0xffffffe4 + iVar3) = param_3;
  *(undefined1 **)(&stack0xffffffe0 + iVar3) = &stack0xffffffe9 + iVar3;
  *(undefined4 *)(&stack0xffffffdc + iVar3) = 0x1a5265;
  _strcpy(*(char **)(&stack0xffffffe0 + iVar3),*(char **)(&stack0xffffffe4 + iVar3));
  (&stack0xffffffe8)[uVar7 + iVar3] = 0x22;
  (&stack0xffffffe9)[uVar7 + iVar3] = 0;
  *(undefined1 **)(&stack0xffffffdc + iVar3) = &stack0xffffffe8 + iVar3;
  *(undefined4 *)(&stack0xffffffd8 + iVar3) = uVar2;
  *(undefined4 *)((int)&uStackY_2c + iVar3) = 0x1a5276;
  pcVar4 = _strstr(*(char **)(&stack0xffffffd8 + iVar3),*(char **)(&stack0xffffffdc + iVar3));
  if (pcVar4 == (char *)0x0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar4 = _strchr(pcVar4 + uVar7 + 1,0x22);
    pcVar4 = pcVar4 + 1;
    uStackY_2c = 0x1a5299;
    pcVar6 = _strchr(pcVar4,0x22);
    if (pcVar6 == (char *)0x0) {
      pcVar5 = (char *)0x0;
    }
    else {
      pcVar5 = (char *)_IOMalloc();
      uStackY_2c = 0x1a52b7;
      _strncpy(pcVar5,pcVar4,(int)pcVar6 - (int)pcVar4);
      pcVar5[(int)pcVar6 - (int)pcVar4] = '\0';
    }
  }
  return pcVar5;
}

