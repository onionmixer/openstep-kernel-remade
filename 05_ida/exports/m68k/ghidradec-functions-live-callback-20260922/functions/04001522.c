
void _move_space_fault(void)

{
  undefined4 in_D1;
  undefined4 in_A0;
  undefined4 in_A1;
  int unaff_A6;
  
  **(undefined4 **)(unaff_A6 + 0x18) = in_D1;
  **(undefined4 **)(unaff_A6 + 0x1c) = in_A0;
  **(undefined4 **)(unaff_A6 + 0x20) = in_A1;
  func_0x04001512();
  return;
}

