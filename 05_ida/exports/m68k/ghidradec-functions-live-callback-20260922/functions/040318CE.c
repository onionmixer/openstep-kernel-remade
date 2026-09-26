
void sub_40318CE(undefined4 *param_1)

{
  *param_1 = *(undefined4 *)
              (_stable +
              ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) *
              4);
  *(undefined4 **)
   (_stable +
   ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) * 4) =
       param_1;
  return;
}

