
void _fd_setbratio(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = *(uint *)(iVar1 + 0x5c);
  uVar3 = *(uint *)(param_1 + 0x186);
  if ((uVar2 < uVar3) || (uVar2 % uVar3 != 0)) {
    *(uint *)(param_1 + 0x176) = *(uint *)(param_1 + 0x176) & 0xfffffffd;
    _printf(aFsBlockNotMult);
    _printf(aFsBlockDDevBlo,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(param_1 + 0x186));
  }
  else {
    *(uint *)(param_1 + 0x196) = uVar2 / uVar3;
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (iVar5 = (int)*(sword *)(*(int *)(param_1 + 0xc) + 0xc), -1 < iVar5)) {
      if (*(int *)(iVar1 + 0x6c) < 0x3c) {
        iVar4 = 0x3c;
      }
      else {
        iVar4 = *(int *)(iVar1 + 0x6c) / 0x3c;
      }
      *(int *)(_dk_bps + iVar5 * 4) = iVar4 * *(int *)(iVar1 + 100) * *(int *)(iVar1 + 0x5c);
    }
  }
  return;
}
