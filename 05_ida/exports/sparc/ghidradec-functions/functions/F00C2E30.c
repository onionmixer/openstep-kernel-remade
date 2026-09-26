
void _ev_lock(char *param_1)

{
  char cVar1;
  
  do {
    cVar1 = *param_1;
    *param_1 = -1;
  } while (cVar1 != '\0');
  return;
}
