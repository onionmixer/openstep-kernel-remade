
void FUN_001ab830(int param_1)

{
  undefined4 *unaff_EBX;
  
  *unaff_EBX = *(undefined4 *)(param_1 + 0x13c);
  *(undefined2 *)(unaff_EBX + 1) = *(undefined2 *)(param_1 + 0x140);
  return;
}

