
void _cache_inval_page(undefined4 param_1)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3,param_1);
  }
  return;
}
