
bool _ev_try_lock(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  *param_1 = -1;
  return cVar1 == '\0';
}
