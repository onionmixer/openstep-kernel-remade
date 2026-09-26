
void _cnputc(char param_1)

{
  (**(code **)(DAT_40b0ae8 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
            ((int)(sword)*(word *)(_cons_tp + 0x38),(int)param_1);
  return;
}

