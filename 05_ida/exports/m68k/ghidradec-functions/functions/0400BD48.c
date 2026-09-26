
void _harderr(int param_1,undefined4 param_2)

{
  _printf(aSDCHardErrorSn,param_2,(*(word *)(param_1 + 0x1e) & 0xff) >> 3,
          (*(word *)(param_1 + 0x1e) & 7) + 0x61,*(undefined4 *)(param_1 + 0x24));
  return;
}
