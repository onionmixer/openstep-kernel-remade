
void sub_407E8B8(int param_1)

{
  _disksort_free(param_1 + 0x60);
  *(undefined4 *)(unk_40B4FDE + *(int *)(param_1 + 4) * 4) = 0;
  _kfree(*(undefined4 *)(param_1 + 0xce),0x1c58);
  _kfree(param_1,0xd6);
  return;
}

