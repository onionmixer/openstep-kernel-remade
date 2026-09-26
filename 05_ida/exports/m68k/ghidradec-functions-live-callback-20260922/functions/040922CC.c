
void __set_timer(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)(CONCAT44(param_2 % 1000,param_3) / 1000);
  if (param_1 == 0) {
    if (uVar1 < 500) {
      uVar1 = 500;
    }
    else if (0xffff < uVar1) {
      uVar1 = 0xffff;
    }
    *_timer_csr = 0;
    *_timer_low = 0xff;
    *_timer_high = (char)(uVar1 >> 8);
    *_timer_low = (char)uVar1;
    *_timer_csr = 0xc0;
    *_timer_low = 0xff;
    *_timer_high = 0xff;
  }
  return;
}

