
void sgetmand(void)

{
  int extraout_A0;
  undefined8 uVar1;
  
  uVar1 = sub_40A0858();
  *(undefined8 *)(extraout_A0 + 4) = uVar1;
  sgetman();
  return;
}
