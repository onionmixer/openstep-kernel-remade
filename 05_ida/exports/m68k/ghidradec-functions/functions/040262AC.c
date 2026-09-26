
void _nfs_attrcache_va(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_1 + 5) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x14) & 8) == 0)) {
    _bcopy(param_2,*(int *)(param_1 + 0x2e) + 0x7c,0x3a);
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    sub_4026304(param_1);
  }
  return;
}
