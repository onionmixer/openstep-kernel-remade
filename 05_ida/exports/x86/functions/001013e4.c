/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1013e4. */
void *__cdecl memcpy(void *__dst, const void *__src, size_t __n)
{
  char *v3; // ebx
  signed __int32 v4; // eax
  int v5; // edx
  int v6; // edx
  char *v7; // ebx
  void *v9; // [esp+Ch] [ebp-4h]
  char *__dsta; // [esp+18h] [ebp+8h]

  v3 = (char *)__src; /*0x1013ed*/
  v4 = __n; /*0x1013f0*/
  v9 = __dst; /*0x1013f6*/
  if ( (int)__n <= 15 ) /*0x1013fc*/
  {
    qmemcpy(__dst, __src, __n); /*0x101405*/
    return v9; /*0x101405*/
  }
  v5 = (unsigned __int8)__src & 3; /*0x10140e*/
  if ( ((unsigned __int8)__src & 3) != 0 ) /*0x101411*/
  {
    qmemcpy(__dst, __src, 4 - v5); /*0x101421*/
    v4 = __n - (4 - v5); /*0x101423*/
    __dst = (char *)__dst + 4 - v5; /*0x10142a*/
    v3 = (char *)__src + 4 - v5; /*0x10142d*/
  }
  qmemcpy(__dst, v3, 4 * (v4 >> 2)); /*0x10143b*/
  v6 = v4 & 3; /*0x10143f*/
  if ( (v4 & 3) != 0 ) /*0x101442*/
  {
    LOBYTE(v4) = v4 & 0xFC; /*0x101444*/
    v7 = &v3[v4]; /*0x101446*/
    __dsta = (char *)__dst + v4; /*0x101448*/
    if ( v6 != 2 ) /*0x10144e*/
    {
      if ( v6 <= 2 ) /*0x101450*/
      {
        if ( v6 != 1 ) /*0x101455*/
          return v9; /*0x101455*/
        goto LABEL_13; /*0x101455*/
      }
      if ( v6 != 3 ) /*0x10145f*/
        return v9; /*0x10145f*/
      __dsta[2] = v7[2]; /*0x101467*/
    }
    __dsta[1] = v7[1]; /*0x101470*/
LABEL_13:
    *__dsta = *v7; /*0x101473*/
  }
  return v9; /*0x101480*/
}
