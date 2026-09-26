
void _cache_push(void)

{
  if (_cpu_type != '\0') {
    pushInvalidateCaches(3);
  }
  return;
}

