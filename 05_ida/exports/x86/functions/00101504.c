/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101504. */
void *__cdecl memmove(void *__dst, const void *__src, size_t __len)
{
  char *v3; // ebx
  signed __int32 v4; // eax
  char *v5; // edx
  size_t v6; // ecx
  int v7; // edx
  int v8; // edx
  char *v9; // ebx
  char *v10; // ebx
  size_t v11; // ecx
  char *v12; // edi
  unsigned int v13; // edx
  int v14; // edx
  char *v16; // [esp+1Ch] [ebp-4h]
  char *__dsta; // [esp+28h] [ebp+8h]

  v3 = (char *)__src; /*0x10150d*/
  v4 = __len; /*0x101510*/
  v16 = (char *)__dst; /*0x101516*/
  if ( __dst > __src && (char *)__src + __len > __dst ) /*0x101522*/
  {
    v5 = (char *)__src + __len; /*0x10151d*/
    v9 = (char *)__src + __len; /*0x101580*/
    __dsta = (char *)__dst + __len; /*0x101587*/
    if ( (int)__len > 16 ) /*0x10158e*/
    {
      v13 = (unsigned __int8)v5 & 3; /*0x10159e*/
      if ( ((unsigned __int8)v9 & 3) != 0 ) /*0x1015a1*/
      {
        qmemcpy(__dsta - 1, v9 - 1, v13); /*0x1015b4*/
        v4 = __len - v13; /*0x1015b6*/
        __dsta -= v13; /*0x1015b8*/
        v9 -= v13; /*0x1015bb*/
      }
      qmemcpy(__dsta - 4, v9 - 4, 4 * (v4 >> 2)); /*0x1015d3*/
      v14 = v4 & 3; /*0x1015d7*/
      if ( (v4 & 3) == 0 ) /*0x1015da*/
        return v16; /*0x1015da*/
      LOBYTE(v4) = v4 & 0xFC; /*0x1015dc*/
      v10 = &v9[-v4 - 1]; /*0x1015e3*/
      v11 = v14; /*0x1015e8*/
      v12 = &__dsta[-v4 - 1]; /*0x1015ea*/
    }
    else
    {
      v10 = v5 - 1; /*0x101590*/
      v11 = __len; /*0x101594*/
      v12 = &v16[__len - 1]; /*0x101596*/
    }
    qmemcpy(v12, v10, v11); /*0x1015ee*/
    return v16; /*0x1015ee*/
  }
  if ( (int)__len <= 15 ) /*0x101527*/
  {
    v6 = __len; /*0x101529*/
LABEL_9:
    qmemcpy(__dst, v3, v6); /*0x101575*/
    return v16; /*0x10157a*/
  }
  v7 = (unsigned __int8)__src & 3; /*0x101532*/
  if ( ((unsigned __int8)__src & 3) != 0 ) /*0x101535*/
  {
    qmemcpy(__dst, __src, 4 - v7); /*0x101545*/
    v4 = __len - (4 - v7); /*0x101547*/
    __dst = (char *)__dst + 4 - v7; /*0x10154e*/
    v3 = (char *)__src + 4 - v7; /*0x101551*/
  }
  qmemcpy(__dst, v3, 4 * (v4 >> 2)); /*0x10155f*/
  v8 = v4 & 3; /*0x101563*/
  if ( (v4 & 3) != 0 ) /*0x101566*/
  {
    LOBYTE(v4) = v4 & 0xFC; /*0x10156c*/
    v3 += v4; /*0x10156e*/
    __dst = (char *)__dst + v4; /*0x101570*/
    v6 = v8; /*0x101573*/
    goto LABEL_9; /*0x101573*/
  }
  return v16; /*0x1015f7*/
}
