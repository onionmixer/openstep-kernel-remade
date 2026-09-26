/* GHIDRADEC_FUNCTION index=488 start=0x401754e */

void _vfs_putmajor(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) != *(int *)(unk_40AE79A + (param_2 + -0x80) * 8)) {
    _vfs_putnum(unk_40B3444,param_2 + -0x80);
  }
  return;
}

