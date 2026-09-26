
void _null_init(void)

{
  int *piVar1;
  
  piVar1 = &_afswitch;
  do {
    if (*piVar1 == 0) {
      *piVar1 = (int)_null_hash;
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < &_ifqmaxlen);
  return;
}

