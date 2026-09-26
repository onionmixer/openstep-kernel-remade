
undefined4 _sdclose(word param_1)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  piVar1 = *(int **)(unk_40B4FDE + uVar2 * 4);
  if (uVar2 < 0x10) {
    if ((*(int *)(*piVar1 + 8) == 0) ||
       (*(sword *)(*(int *)(*(int *)(*piVar1 + 8) + 0x10) + 0x1a) == 0)) {
      return 6;
    }
    bVar3 = (byte)(1 << (param_1 & 7));
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)piVar1 + 0xd) = ~bVar3 & *(byte *)((int)piVar1 + 0xd);
    }
    else {
      *(byte *)(piVar1 + 3) = ~bVar3 & *(byte *)(piVar1 + 3);
    }
    if (((*(char *)(piVar1 + 3) == '\0' && *(char *)((int)piVar1 + 0xd) == '\0') &&
        (*(char *)(*(int *)(*piVar1 + 0xb2) + 1) < '\0')) &&
       ((*(byte *)((int)piVar1 + 0xb) & 2) == 0)) {
      sub_407F330(piVar1);
    }
  }
  return 0;
}

