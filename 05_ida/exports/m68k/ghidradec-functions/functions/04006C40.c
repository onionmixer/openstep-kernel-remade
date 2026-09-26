
void _pidhash_enter(int param_1)

{
  uint uVar1;
  
  uVar1 = *(word *)(param_1 + 0x30) & 0x3f;
  *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(_pidhash + uVar1 * 4);
  *(int *)(_pidhash + uVar1 * 4) = param_1;
  return;
}
