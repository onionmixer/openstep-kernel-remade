
undefined4 sub_407FC78(int *param_1,byte *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*param_2 < 8) && (param_2[1] < 8)) {
    iVar3 = *param_1;
    if (*(byte *)(iVar3 + 0x1c) != 0xff) {
      pcVar1 = (char *)(*(int *)(iVar3 + 0x18) + (uint)*(byte *)(iVar3 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar3 + 0x1d));
      *pcVar1 = *pcVar1 + -1;
      *(undefined *)(*param_1 + 0x1c) = 0xff;
      *(undefined *)(*param_1 + 0x1d) = 0xff;
    }
    if ((*(char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]) != '\0'
        ) && (iVar3 = _suser(), iVar3 == 0)) {
      return 0xd;
    }
    pcVar1 = (char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]);
    *pcVar1 = *pcVar1 + '\x01';
    *(byte *)(*param_1 + 0x1c) = *param_2;
    *(byte *)(*param_1 + 0x1d) = param_2[1];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
