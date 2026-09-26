
undefined8 _dma_dequeue(int *param_1,int param_2)

{
  int *piVar1;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  
  piVar1 = (int *)*param_1;
  if ((piVar1 == (int *)0x0) || ((param_2 == 0 && (piVar1[4] == 0)))) {
    piVar1 = (int *)0x0;
  }
  else {
    *param_1 = *piVar1;
  }
  return CONCAT44(piVar1,(int)(sword)(word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1
                                                 | in_CF));
}

