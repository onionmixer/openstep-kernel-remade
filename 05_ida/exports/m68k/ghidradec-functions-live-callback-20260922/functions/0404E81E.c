
undefined8 _ticks_to_ns_time(uint param_1)

{
  return CONCAT44(_ns_per_tick * param_1 + (int)((qword)dword_40C2448 * (qword)param_1 >> 0x20),
                  (int)((qword)dword_40C2448 * (qword)param_1));
}

